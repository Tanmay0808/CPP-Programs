#include<iostream>
using namespace std;

///Only Applicable For First N Natural Numbers
void MissingElemUsingSum(int *Arr,int s)
{
   int sum = 0,n = Arr[s-1];
   for (int i=0;i<s;i++)
      sum += Arr[i];
   int s_val = (n*(n+1))/2;
   if (s_val == sum)
      cout<<"\nNo Element Is Missing"<<endl;
   else
      cout<<"\nMissing Element Using Sum Of Elements Method : "<<s_val - sum<<endl;
}

///Applicable To All Series OfContinuous Numbers
void MissingElemUsingDiff(int *Arr,int s)
{
   int l = Arr[0],diff = l - 0;
   for (int i=0;i<s;i++){
      if ((Arr[i] - i) != diff )
      {
         cout<<"\nMissing Element Using Diff Of Elem And Index Value : "<<i + diff<<endl;
         break;
      }
   }
}

int main()
{
   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   int Arr[s];
   cout<<"\nEnter Array Elements : "<<endl;
   for (int i=0;i<s;i++)
      cin>>Arr[i];

   if (Arr[0] == 1)
      MissingElemUsingSum(Arr,s);
   MissingElemUsingDiff(Arr,s);

   return 0;
}

#include<iostream>
using namespace std;

void MissingElement(int *A, int s)
{
   int diff = A[0] - 0,k=1;
   for (int i=0;i<s;i++)
   {
      if ((A[i] - i) != diff)
      {
         while (diff < (A[i] - i)){
            cout<<"\n"<<k++<<" Missing Element : "<<i + diff<<endl;
            diff++;
         }
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

   MissingElement(Arr,s);

   return 0;
}

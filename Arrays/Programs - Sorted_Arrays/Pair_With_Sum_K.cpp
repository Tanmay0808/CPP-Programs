#include<iostream>
using namespace std;

void PairWithSum(int *A,int n, int sum)
{
   int i=0,j=n-1,k=1;
   while (i<j)
   {
      if (A[i] + A[j] == sum)
      {
         cout<<"\n"<<k++<<" Pair With Required Sum Is ( "<<A[i]<<" , "<<A[j]<<" )"<<endl;
         i++;
         j--;
      }
      else if(A[i] + A[j] < sum)
         i++;
      else
         j--;
   }
}

int main()
{
   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   int A[s];
   cout<<"\nEnter Array Elements : "<<endl;
   for (int i=0;i<s;i++)
      cin>>A[i];

   cout<<"\nEnter Sum : ";
   int sum;
   cin>>sum;

   PairWithSum(A,s,sum);

   return 0;
}

#include<iostream>
using namespace std;

void PairWithSum(int *A, int n, int sum)
{
   int k=1;
   for (int i=0;i<n-1;i++)
   {
      for (int j=i+1;j<n;j++)
      {
         if (A[i] + A[j] == sum)
         {
            cout<<"\n"<<k++<<" Pair With Required Sum Is ( "<<A[i]<<" , "<<A[j]<<" )"<<endl;
         }
      }
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

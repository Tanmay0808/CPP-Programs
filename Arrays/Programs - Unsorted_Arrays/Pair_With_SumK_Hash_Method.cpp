#include<iostream>
using namespace std;

void PairWithSum_HashMethod(int *A, int n, int sum)
{
   int k=1;
   int *B = new int[A[n-1] + 1];
   ///Initialing B to Zero
   for (int i=0;i<A[n-1]+1;i++)
      B[i] = 0;

   ///Checking And Updating Elements In B
   for (int i=0;i<n;i++)
   {
      if (B[sum - A[i]] !=0)
         cout<<"\n"<<k++<<" Pair With Required Sum Is ( "<<A[i]<<" , "<<sum-A[i]<<" )"<<endl;
      B[A[i]]++;
   }
   delete []B;
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

   PairWithSum_HashMethod(A,s,sum);

   return 0;
}

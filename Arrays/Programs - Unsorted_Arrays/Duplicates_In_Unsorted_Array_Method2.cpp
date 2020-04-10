#include<iostream>
using namespace std;

void DuplicatesUsingHash(int *A, int n)
{
   int l = A[0],h = A[n-1];
   int *B  = new int[h+1];
   for (int i=0;i<n;i++)
   {
      B[A[i]]++;
   }
   ///Printing Duplicates
   for (int i=0;i<h+1;i++)
   {
      if (B[i]>1)
      {
         cout<<"\nDuplicates Of Element "<<i<<" = "<<B[i]<<endl;
      }
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

   DuplicatesUsingHash(A,s);

   return 0;
}

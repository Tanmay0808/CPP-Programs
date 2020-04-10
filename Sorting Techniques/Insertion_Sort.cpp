#include<iostream>
using namespace std;

void InsertionSort(int *A, int n)
{
   for (int i=1;i<n;i++)
   {
      int j = i-1, x = A[i];
      while( j>-1 && A[j] > x)
      {
         A[j+1] = A[j];
         j--;
      }
      A[j+1] = x;
   }
}

int main()
{
   cout<<"Enter No. Of Elements : ";
   int n;
   cin>>n;

   int A[n];
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];

   cout<<"\nInsertion Sort : "<<endl;
   InsertionSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

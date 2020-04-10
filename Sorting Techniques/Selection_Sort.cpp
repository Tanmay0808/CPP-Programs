#include<iostream>
using namespace std;

void SelectionSort(int *A, int n)
{
   int j,k;
   for (int i=0;i<n-1;i++)
   {
      for (j = k = i;j<n;j++)
      {
         if (A[j] < A[k])
            k = j;
      }
      swap(A[i],A[k]);
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

   cout<<"\nSelection Sort : "<<endl;
   SelectionSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

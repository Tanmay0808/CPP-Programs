#include<iostream>
#include<limits.h>
using namespace std;

int Partition(int *A, int l, int h)
{
   int piv = A[l];
   int i = l, j =h;
   do{
      do{i++;}while(A[i] <= piv);
      do{j--;}while(A[j] > piv);
      if (i < j)
         swap(A[i],A[j]);
   }while(i<j);
   swap(A[l],A[j]);
   return j;
}

void QuickSort(int *A, int l, int h)
{
   int j;
   if (l<h)
   {
      j = Partition(A,l,h);
      QuickSort(A,l,j);
      QuickSort(A,j+1,h);
   }
}

int main()
{
   cout<<"Enter No. Of Elements : ";
   int n;
   cin>>n;

   int A[n+1];
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];
   A[n] = INT_MAX;

   cout<<"\nQuick Sort : "<<endl;
   QuickSort(A,0,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

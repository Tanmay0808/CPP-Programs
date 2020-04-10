#include<iostream>
using namespace std;

void mergeLists(int *A, int l, int mid, int h)
{
   int i = l,j = mid+1,k=l;
   int B[100];
   while (i<=mid && j<=h)
   {
      if (A[i] < A[j])
         B[k++] = A[i++];
      else
         B[k++] = A[j++];
   }
   for (;j<=h;j++)
      B[k++] = A[j];
   for (;i<=mid;i++)
      B[k++] = A[i];
   for (int i=l;i<=h;i++)
      A[i] = B[i];
}

void IterativeMergeSort(int *A, int n)
{
   int l,h,mid,p;
   for (p=2;p<=n;p=p*2)
   {
      for (int i=0; i+p-1<n;i=i+p)
      {
         l = i;
         h = i + p - 1;
         mid = (l + h)/2;
         mergeLists(A,l,mid,h);
      }
   }
   if (p/2 < n)
      mergeLists(A,0,p/2-1,n);
}

void RecursiveMergeSort(int *A, int l, int h)
{
   if (l<h)
   {
      int mid = (l+h)/2;
      RecursiveMergeSort(A,l,mid);
      RecursiveMergeSort(A,mid+1,h);
      mergeLists(A,l,mid,h);
   }
}

int main()
{
   cout<<"Enter No. Of Elements : ";
   int n;
   cin>>n;

   int A[n];
   cout<<"\nUsing Recursion : -- \n\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];

   cout<<"\nRecursive Merge Sort : "<<endl;
   RecursiveMergeSort(A,0,n-1);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   cout<<"\n\nUsing Iteration : -- \n\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];

   cout<<"\nIterative Merge Sort : "<<endl;
   IterativeMergeSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

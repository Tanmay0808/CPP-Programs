#include<iostream>
using namespace std;

void insertion(int *A ,int n, int gap)
{
   int i=0,j=i+gap;
   while (j < n)
   {
      while (i > -1 && A[j] < A[i])
      {
         swap(A[j],A[i]);
         j = i;
         i = i - gap;
      }
      i++;
      j=i+gap;
   }
}

void ShellSort(int *A, int n)
{
    int gap = n/2;
    while (gap >= 1)
    {
       insertion(A, n, gap);
       gap = gap/2;
    }
}

int main(){
   cout<<"Enter No. Of Elements : ";
   int n;
   cin>>n;

   int A[n];
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<n;i++)
      cin>>A[i];

   cout<<"\nShell Sort : "<<endl;
   ShellSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

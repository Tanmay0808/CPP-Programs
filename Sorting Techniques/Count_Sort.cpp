#include<iostream>
#include<limits.h>
using namespace std;

int findMax(int *A, int n)
{
   int max = INT_MIN;
   for (int i=0;i<n;i++)
   {
      if (A[i] > max)
         max = A[i];
   }
   return max;
}

void CountSort(int *A, int n)
{
   int max = findMax(A,n);
   int cnt[max+1];

   for (int i=0;i<max+1;i++)
      cnt[i] = 0;

   for (int i=0;i<n;i++)
   {
      cnt[A[i]]++;
   }

   int i=0,j=0;
   while (i < max + 1)
   {
      if (cnt[i]!=0)
      {
         A[j++] = i;
         cnt[i]--;
      }
      else{
         i++;
      }
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

   cout<<"\nCount Sort : "<<endl;
   CountSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

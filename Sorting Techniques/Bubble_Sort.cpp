#include<iostream>
using namespace std;

void BubbleSort(int *A, int n)
{
   int flg = 0;
   for (int i=0; i<n-1 ;i++)
   {
      for (int j=0;j<n-1-i;j++)
      {
         if (A[j] > A[j+1])
         {
            swap(A[j],A[j+1]);
            flg = 1;
         }
      }
      if (flg == 0)
         break;
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

   cout<<"\nBubble Sort : "<<endl;
   BubbleSort(A,n);
   for (int i=0;i<n;i++)
      cout<<A[i]<<"  ";
   cout<<endl;

   return 0;
}

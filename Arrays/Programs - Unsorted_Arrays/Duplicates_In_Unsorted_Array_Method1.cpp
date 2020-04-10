#include<iostream>
using namespace std;

void DuplicatesUnsortedArr(int *A, int n)
{
   for (int i=0;i<n-1;i++)
   {
      int cnt = 1;
      for (int j=i+1;j<n;j++)
      {
         if (A[i]!=-1 && A[j] == A[i]){
            cnt += 1;
            A[j] = -1;
         }
      }
      if (cnt > 1)
         cout<<"\nDuplicates Found For Element "<<A[i]<<" = "<<cnt<<endl;
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

   DuplicatesUnsortedArr(A,s);

   return 0;
}

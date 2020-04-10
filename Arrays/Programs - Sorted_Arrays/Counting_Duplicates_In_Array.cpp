#include<iostream>
using namespace std;

void CountDuplicates(int *A, int n)
{
   int last_dup = 0,k=1,j;
   for (int i=0;i<n;i++)
   {
      if (A[i]==A[i+1]  && A[i]!=last_dup)
      {
         j = i+1;
         while (A[j] == A[i]){j++;}
         cout<<"\n"<<"Element "<<A[i]<<" Has "<<j-i<<" Duplicates"<<endl;
         i = j-1;
      }
   }
}

int main()
{
   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   int Arr[s];
   cout<<"\nEnter Array Elements : "<<endl;
   for (int i=0;i<s;i++)
      cin>>Arr[i];

   CountDuplicates(Arr,s);

   return 0;
}

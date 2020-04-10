#include<iostream>
using namespace std;

void FindDuplicates(int *A, int n)
{
   int last_dup = 0,k=1;
   for (int i=0;i<n;i++)
   {
      if (A[i] == A[i+1]  && A[i] != last_dup)
      {
         cout<<"\n"<<k++<<" Element Whose Duplicate Is Found : "<<A[i]<<endl;
         last_dup = A[i];
      }
   }
}

int main()
{
   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   int arr[s];
   cout<<"\nEnter Array Elements : "<<endl;
   for (int i=0;i<s;i++)
      cin>>arr[i];

   FindDuplicates(arr,s);

   return 0;
}

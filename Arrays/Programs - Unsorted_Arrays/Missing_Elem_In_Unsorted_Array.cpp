#include<iostream>
using namespace std;

void MissingElem (int *A, int n)
{
   int g=1;
   ///Entering Max Elem Always At The End
   int *B = new int[A[n-1] + 1];

   ///Making All Elements Zero
   for (int i=0;i<A[n-1];i++)
   {
      B[i] = 0;
   }

   ///Setting Elements To One
   for (int j=0;j<n;j++)
   {
      B[A[j]]++;
   }

   ///Printing Missing Elements
   for (int i=1;i<A[n-1];i++)
   {
      if (B[i] == 0)
         cout<<"\n"<<g++<<" Missing Elem : "<<i<<endl;
   }
   delete []B;
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

   MissingElem(Arr,s);

   return 0;
}

#include<iostream>
using namespace std;

void FindNCountDuplicates(int *A,int n)
{
  int l=A[0],h=A[n-1];
  int *B = new int[h+1];

  ///Initialising B To Zero
  for (int i=0;i<h+1;i++)
     B[i] = 0;
  ///Increments Elements Of A By Assuming Them As Indices Of B
  for (int i=0;i<n-1;i++){
     B[A[i]]++;
  }
  ///Chceking Duplicates
  for (int i=1;i<h;i++)
  {
     if (B[i]>1)
     {
        cout<<"\nElement "<<i<<" Has "<<B[i]<<" Duplicates"<<endl;
     }
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

   FindNCountDuplicates(Arr,s);

   return 0;
}

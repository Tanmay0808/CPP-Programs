#include<iostream>
using namespace std;

void MaxNMinElem(int *A, int n)
{
   int min_val = A[0],max_val = A[0];
   for (int i=1;i<n;i++)
   {
      if (A[i] < min_val)
         min_val = A[i];
      else if (A[i] > max_val)
         max_val = A[i];
   }
   cout<<"\nMinimum Value : "<<min_val<<endl<<"Maximum Value : "<<max_val<<endl;
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

  MaxNMinElem(A,s);

  return 0;
}

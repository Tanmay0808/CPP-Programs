#include<iostream>
using namespace std;

void DifferenceOfArrays(int *A,int *B,int m,int n)
{
   int c[m],k=0;
   ///Adding A's Elements That Are Not In B
   for (int i=0;i<m;i++)
   {
      int flg = 0;
      for (int j=0;j<n;j++)
      {
         if (A[i] == B[j])
         {
            flg = 1;
            break;
         }
      }
      if (!flg)
      {
         c[k++] = A[i];
      }
   }

   ///Displaying Difference A - B
   cout<<"\nDifference Of Arrays (A - B) : "<<endl;
   for (int i=0;i<k;i++)
      cout<<c[i]<<" ";
   cout<<endl;
}


int main(){

  cout<<"Enter The Size Of The First Array : ";
  int s1;
  cin>>s1;
  cout<<"\nEnter The Size Of Second Array : ";
  int s2;
  cin>>s2;

  int A[s1],B[s2];
  cout<<"\nEnter First Array Elements : "<<endl;
  for (int i=0;i<s1;i++)
     cin>>A[i];
  cout<<"\nEnter Second Array Elements : "<<endl;
  for (int i=0;i<s2;i++)
     cin>>B[i];

  DifferenceOfArrays(A,B,s1,s2);

  return 0;
}


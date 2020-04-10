#include<iostream>
using namespace std;

void UnionOfArrays(int *A,int *B,int m,int n)
{
   int c[m+n],k=0;
   ///Copying Elements Of A
   for (int i=0;i<m;i++)
   {
      c[k++] = A[i];
   }

   ///Adding Elements Of B That Are Not In A
   for (int i=0;i<n;i++)
   {
      int flg = 0;
      for (int j=0;j<m;j++)
      {
         if (B[i] == A[j]){
            flg=1;
            break;
         }
      }
      if (!flg)
      {
         c[k++] = B[i];
      }
   }

   ///Displaying Array
   cout<<"\nUnion Of Arrays : "<<endl;
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

  UnionOfArrays(A,B,s1,s2);

  return 0;
}

#include<iostream>
using namespace std;

void InterSectionOfArrays(int *A,int *B,int m,int n)
{
   int c[m+n],k=0;
   for (int i=0;i<m;i++)
   {
      int flg = 0,repeat_flg = 0;
      ///Condition To Avoid Duplicate Elements
      for (int l=0;l<k;l++){
         if (A[i] == c[l])
            repeat_flg = 1;
            break;
      }
      if (repeat_flg)
         continue;

      ///Actual Pushing Of Common Elements To Array C
      for (int j=0;j<n;j++)
      {
         if (A[i] == B[j])
         {
            flg = 1;
            break;
         }
      }
      if (flg)
      {
         c[k++] = A[i];
      }
   }

   ///Display
   cout<<"\nIntersection Of Arrays : "<<endl;
   for (int i=0;i<k;i++){
      cout<<c[i]<<" ";
   }
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

  InterSectionOfArrays(A,B,s1,s2);

  return 0;
}


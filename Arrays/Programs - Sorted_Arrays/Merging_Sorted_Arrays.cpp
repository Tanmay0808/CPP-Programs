#include<iostream>
using namespace std;

void MergeArrays(int *A, int *B,int m,int n){
   int c[m+n];
   int i=0,j=0,k=0;
   while (i<m && j<n){
      if (A[i] < B[j])
         c[k++] = A[i++];
      else
         c[k++] = B[j++];
   }
   for (;i<m;i++)
      c[k++] = A[i];
   for (;j<n;j++)
      c[k++] = B[j];

   cout<<"\nMerged Array : "<<endl;
   for (int i=0;i<m+n;i++){
      cout<<c[i]<<" ";
   }
   cout<<endl;

}

int main(){

   cout<<"Enter The Size Of The First Array : ";
   int s1;
   cin>>s1;

   cout<<"\nEnter The Size Of The Second Array : ";
   int s2;
   cin>>s2;

   cout<<"\nEnter First Array Elements : "<<endl;
   int A[s1];
   for (int i=0;i<s1;i++){
      cin>>A[i];
   }

   cout<<"\nEnter Second Array Elements : "<<endl;
   int B[s2];
   for (int i=0;i<s2;i++){
      cin>>B[i];
   }

   MergeArrays(A,B,s1,s2);

   return 0;
}

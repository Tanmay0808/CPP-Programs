#include<iostream>
using namespace std;

int main(){

   cout<<"Enter No. Of Rows :";
   int r;
   cin>>r;

   cout<<"\nEnter No. Of Columns :";
   int c;
   cin>>c;

   ///CReating An Array Of Pointers, Then Assigning Each Pointer , An Array
   int *arr[r];
   for (int i=0;i<r;i++)
      arr[i] = new int[c];

  ///Filling Array
   for (int i=0;i<r;i++){
      cout<<"\nRow Number : "<<i<<endl;
      for(int j=0;j<c;j++){
         cin>>arr[i][j];
      }
   }

   ///Displayin Array
   cout<<"\n2-D Array : "<<endl;
   for (int i=0;i<r;i++){
      for(int j=0;j<c;j++){
         cout<<arr[i][j]<<" ";
      }
      cout<<endl;
   }

   ///De-Allocating Memory
   for (int i=0;i<r;i++)
      delete arr[i];

   return 0;
}

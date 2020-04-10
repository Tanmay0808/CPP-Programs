#include<iostream>
using namespace std;

///Negative Numbers If Found On Right Side Will Be Moved To Left
void NegNumOnLeft(int *arr,int arr_size){
   int i = 0,j = arr_size - 1;
   while (i < j){
      while (arr[i]<0){i++;}
      while (arr[j]>=0){j--;}
      if (i < j){
         swap(arr[i],arr[j]);
      }
   }
}

int main(){

   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   cout<<"\nEnter The Elements : "<<endl;
   int arr[s];
   for (int i=0;i<s;i++)
      cin>>arr[i];

   cout<<"\nArray : "<<endl;
   for (int i=0;i<s;i++)
      cout<<arr[i]<<" ";
   cout<<endl;

   NegNumOnLeft(arr,s);
   cout<<"\nArray With Negative Numbers On Left : "<<endl;
   for (int i=0;i<s;i++)
      cout<<arr[i]<<" ";
   cout<<endl;

   return 0;
}

#include<iostream>
using namespace std;

bool CheckSorted(int *arr,int arr_size){

   for (int i=0;i<arr_size-1;i++){
      if (arr[i] > arr[i+1])
         return false;
   }
   return true;

}

int main(){

   cout<<"Enter The Size Of THe Array : ";
   int s;
   cin>>s;

   cout<<"\nEnter The Elements : "<<endl;
   int arr[s];

   for (int i=0;i<s;i++)
      cin>>arr[i];

   if (CheckSorted(arr,s)){
      cout<<"\nArray Is Sorted"<<endl;
   }
   else{
      cout<<"\nArray Is Not Sorted"<<endl;
   }

   return 0;
}



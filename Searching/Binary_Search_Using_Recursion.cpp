#include<iostream>
using namespace std;

int BinSearchRecursion(int arr[], int elem, int l, int h){
   int mid;
   if (l <= h){
      mid = (l + h)/2;
      if (arr[mid] == elem){
         return mid;
      }
      else if (arr[mid] > elem){
         return BinSearchRecursion(arr,elem,l,mid - 1);
      }
      else{
         return BinSearchRecursion(arr,elem,mid + 1,h);
      }
   }
   return -1;
}

int main(){

   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   cout<<"\nEnter Array Elements : \n";
   int arr[s];
   for (int i=0;i<s;i++){
      cin>>arr[i];
   }

   cout<<"\nEnter The Element To Be Searched : ";
   int elem;
   cin>>elem;

   int result = BinSearchRecursion(arr,elem,0,s-1);

   if (result == -1){
      cout<<"\nElement Not Found"<<endl;
   }
   else{
      cout<<"\nElement Found At Index : "<<result<<endl;
   }
   return 0;
}

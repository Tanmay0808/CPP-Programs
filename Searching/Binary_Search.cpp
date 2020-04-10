#include<iostream>
using namespace std;

int BinSearch(int *arr,int arr_size,int elem){
   int l=0,h = arr_size-1,mid=0;
   while (l <= h){
      mid = (l + h)/2;
      if (arr[mid] == elem){
         return mid;
      }else if (arr[mid] > elem){
         h = mid - 1;
      }else if (arr[mid] < elem){
         l = mid + 1;
      }
   }
   return -1;
}

int main(){

   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   cout<<"\nEnter The Elements : "<<endl;
   int arr[s];
   for (int i=0;i<s;i++){
      cin>>arr[i];
   }

   cout<<"\nEnter The Element To Be Searched : ";
   int elem;
   cin>>elem;

   int res = BinSearch(&arr[0],s,elem);
   if (res == -1){
      cout<<"\nElement Not Found"<<endl;
   }else{
      cout<<"Element Found At Index : "<<res<<endl;
   }

   return 0;
}

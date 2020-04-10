#include<iostream>
using namespace std;

int LinSearch(int *ar,int ar_size,int elem){
   for (int i=0;i<ar_size;i++){
      if (elem == ar[i]){
          return i;
      }
   }
   return -1;
}

int main(){

   cout<<"Enter The Size Of The Array :";
   int s;
   cin>>s;

   cout<<"\nEnter Array Elements : "<<endl;
   int arr[s];
   for (int i=0;i<s;i++){
      cin>>arr[i];
   }

   cout<<"\nEnter The Elements To Be Searched : ";
   int elem;
   cin>>elem;

   int res = LinSearch(&arr[0],s,elem);

   if (res == -1){
      cout<<"\nElement Not Found"<<endl;
   }else{
      cout<<"Element Found At Index : "<<res<<endl;
   }
   return 0;
}

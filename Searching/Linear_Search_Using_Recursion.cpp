#include<iostream>
using namespace std;

int LinSearchRecursion(int *arr,int size_arr,int elem)
{
   static int i = 0;
   if (i < size_arr ){
      if (arr[i] == elem){
         return i;
      }
      else{
         i++;
         return LinSearchRecursion(arr,size_arr,elem);
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
   int res = LinSearchRecursion(arr,s,elem);
   if (res == -1){
      cout<<"\nElement Not Found"<<endl;
   }
   else{
      cout<<"\nElement Found At Index : "<<res<<endl;
   }
   return 0;
}

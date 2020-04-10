#include<iostream>
using namespace std;

void Insertion(int *arr, int arr_size, int elem){
   int i = arr_size - 1;
   while (arr[i] > elem){
      arr[i+1] = arr[i];
      i--;
   }
   arr[i+1] = elem;
}

int main(){

   cout<<"Enter The Size Of The Array : ";
   int s;
   cin>>s;

   cout<<"\nEnter Number Of Elements To Initialize : ";
   int n;
   cin>>n;

   int arr[s];
   for (int i=0;i<n;i++)
     cin>>arr[i];

   ///INSERTION
   cout<<"\nEnter Element To Insert : ";
   int elem;
   cin>>elem;

   Insertion(arr,n,elem);

   cout<<"\nArray After Insertion : "<<endl;
   for (int i=0;i<n+1;i++)
      cout<<arr[i]<<" ";
   cout<<endl;

   return 0;
}

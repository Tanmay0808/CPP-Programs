#include<iostream>
#include "ArrayHeader.h"
using namespace std;

template <class T>
void Array<T>::Display(){
   cout<<"\nDisplaying The Array : \n";
   for (int i=0;i<length;i++){
      cout<<A[i]<<" ";
   }
   cout<<endl;
}

template <class T>
void Array<T>::AddElem(){
   cout<<"\nEnter Element To Add : ";
   T x;
   cin>>x;

   cout<<"\nAdding Element "<<x<<" To The Array ( Append ) : "<<endl;
   A[length] = x;
   length++;
}

template <class T>
void Array<T>::Insert(){
   cout<<"\nEnter Element To Insert : ";
   T x;
   cin>>x;

   cout<<"\nEnter The Index To Insert Element : ";
   int index=0;
   cin>>index;

   cout<<"\nElement Will Be Added At Pos : "<<index<<endl;
   for (int i=length;i>index;i--){
      A[i] = A[i-1];
   }
   A[index] = x;
   length++;
}

template <class T>
void Array<T>::Delete(){
   cout<<"\nEnter The Index To Delete Element : \n";
   int index=0;
   cin>>index;

   cout<<"\nElement At Index "<<index<<" Will Be Deleted"<<endl;
   A[index] = 0;
   for (int i=index;i<length-1;i++){
      A[i] = A[i+1];
   }
   length--;
}

template <class T>
void Array<T>::Search(){
   cout<<"\nEnter The Element To Be Searched : ";
   T elem;
   cin>>elem;

   for (int i=0;i<length;i++){
      if (A[i] == elem){
         cout<<"\nElement Found At Index : "<<i<<endl;
         return;
      }
   }
   cout<<"\nElement Not Found"<<endl;
}

template <class T>
void Array<T>::Reverse(){
   for (int i=length-1,j=0;j<i;i--,j++){
      swap(A[i],A[j]);
   }
   ///Display Array
   cout<<"\nReversed Array : "<<endl;
   for (int j = 0; j<length;j++)
      cout<<A[j]<<" ";
   cout<<endl;
}

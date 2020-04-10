#include<iostream>
using namespace std;

///Function Calling Itself At The Beginning : HeadRecursion
void fun(int n){

   if (n>0){

      fun (n-1);
      cout<<n<<"  ";

   }

}

int main(){

   cout<<"Enter Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nOutput Of Head Recursion : "<<endl;
   fun(n);
   cout<<endl;
   return 0;

}

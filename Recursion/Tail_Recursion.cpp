#include<iostream>
using namespace std;

///Function Calling Itself At The End : TailRecursion
void func(int n){

   if (n>0){

      cout<<n<<"  ";
      func(n-1);

   }

}

int main(){

   cout<<"Enter The Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nOutput Of Tail Recursion : "<<endl;
   func (n);
   cout<<endl;
   return 0;

}

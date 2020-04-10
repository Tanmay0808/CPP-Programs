#include<iostream>
using namespace std;

int NestedRecur(int n){

   if (n > 100){

      return n - 10;

   }
   return NestedRecur(NestedRecur(n + 11));

}

int main(){

   cout<<"Enter Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nOutput Of Nested Recursion : "<<endl;
   int result = NestedRecur (n);
   cout<<result<<endl;
   return 0;

}

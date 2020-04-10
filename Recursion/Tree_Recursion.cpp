#include<iostream>
using namespace std;

///Function Calling Itself More Than Once : TreeRecursion
void TreeRecur (int n){

   if (n > 0){

       cout<<n<<"  ";
       TreeRecur(n-1);
       TreeRecur(n-1);

   }

}

int main(){

   cout<<"Enter Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nOutput Of Tree Recursion : "<<endl;
   TreeRecur (n);
   cout<<endl;
   return 0;

}

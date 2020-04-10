#include<iostream>
using namespace std;

///Function Calling Other Function And That Function Calling First One : IndirectRecursion
void funB (int n);

void funA(int n){

   if (n>0){

      cout<<n<<"  ";
      funB(n-1);

   }

}

void funB(int n){

   if (n > 1){

      cout<<n<<"  ";
      funA(n/2);

   }

}

int main(){

   cout<<"Enter Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nOutput Of Indirect Recursion : "<<endl;
   funA(n);
   cout<<endl;
   return 0;

}

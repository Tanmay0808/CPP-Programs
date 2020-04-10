#include<iostream>
using namespace std;

int Power(int n, int p){

   if (p == 0){

      return 1;

   }
   return n * Power(n,p-1);

}

int main(){

   cout<<"Enter The Number : ";
   int num;
   cin>>num;

   cout<<"\nEnter Power : ";
   int pow;
   cin>>pow;

   cout<<"\n"<<num<<" Raised To Power "<<pow<<" ( "<<num<<" ^ "<<pow<<" )  =  ";
   int result = Power(num , pow);
   cout<<result<<endl;
   return 0;

}

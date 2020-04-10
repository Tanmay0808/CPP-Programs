#include<iostream>
using namespace std;

int Fact (int n){

   if (n == 0){

      return 1;

   }
   return n * Fact(n-1);

}

int main(){

   cout<<"Enter Any Positive Number N : ";
   int n;
   cin>>n;

   cout<<"\nFactorial ("<<n<<")  =  ";
   int a = Fact(n);
   cout<<a<<endl;
   return 0;

}

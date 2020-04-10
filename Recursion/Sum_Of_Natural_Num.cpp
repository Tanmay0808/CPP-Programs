#include<iostream>
using namespace std;

int SumNatural (int n){

   if (n == 0){
      return 0;
   }

   return n + SumNatural(n-1);

}

int main(){

   cout<<"Enter Value Of N : ";
   int n;
   cin>>n;

   cout<<"\nSum Of First "<<n<<" Natural Numbers Is : ";
   int res = SumNatural (n);
   cout<<res<<endl;
   return 0;

}

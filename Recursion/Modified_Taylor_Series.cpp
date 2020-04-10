#include<iostream>
using namespace std;

///Taylor Series  (e^x) = 1 + x/1 + x^2/2! + x^3/3! .......
///Modified Version To Reduce The No. Of Multiplications
double e(int x, int n){

   static double s = 1.0;
   if (n==0)
      return s;
   s = 1 + (static_cast<double>(x)/n)*s;
   return e(x,n-1);

}

int main(){

   cout<<"Enter Value Of X : ";
   int x;
   cin>>x;

   cout<<"\nEnter Number Of Terms To Approximate : ";
   int n;
   cin>>n;

   cout<<"\nResult Of Taylor Series ( e ^ "<<x<<" ) Upto "<<n<<" Terms  = ";
   double result = e(x,n);
   cout<<result<<endl;
   return 0;
}


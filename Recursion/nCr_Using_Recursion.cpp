#include<iostream>
using namespace std;

int C (int n, int r){

   if (r==0 || n==r)
   {
      return 1;
   }
   return C(n-1,r-1) + C(n-1,r);

}

int main(){

  cout<<"Enter Value Of N : ";
  int n;
  cin>>n;

  cout<<"\nEnter Value Of R : ";
  int r;
  cin>>r;

  cout<<"\nC ("<<n<<" , "<<r<<")  =  ";
  int result = C(n,r);
  cout<<result<<endl;

  return 0;
}

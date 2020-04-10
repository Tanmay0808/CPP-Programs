#include<iostream>
using namespace std;

int F[10];

int fibb (int n){

   if (n <= 1){
      F[n] = n;
      return n;
   }
   else{
      if (F[n-2] == -1){
         F[n-2] = fibb(n-2);
      }
      if (F[n-1] == -1){
         F[n-1] = fibb(n-1);
      }
      F[n] = F[n-2] + F[n-1];
      return F[n-2] + F[n-1];
   }

}

int main(){

   cout<<"Enter The Value Of N : ";
   int n;
   cin>>n;
   for (int i=0;i<10;i++){
      F[i] = -1;
   }

   cout<<"\nValue Of Fibbonaci Term "<<n<<" : ";
   int result = fibb(n);
   cout<<result<<endl;

   return 0;
}


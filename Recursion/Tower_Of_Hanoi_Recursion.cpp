#include<iostream>
using namespace std;

///Tower Of Hanoi
void TowerOfHanoi ( int n, char source, char aux, char target){

   if (n > 0){
      TowerOfHanoi(n-1 , source, target , aux);
      cout<<"Move Disk From  "<<source<<"  To  "<<target<<endl;
      TowerOfHanoi(n-1, aux, source, target);
   }

}

int main(){

   cout<<"Enter Number Of Disks : ";
   int n;
   cin>>n;

   cout<<endl;
   TowerOfHanoi(n,'A','B','C');

   return 0;
}

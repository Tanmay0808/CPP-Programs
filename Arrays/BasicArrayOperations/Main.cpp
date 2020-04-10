#include<iostream>
#include "ArrayClassMethods.cpp"
#include "ArrayHeader.h"
using namespace std;

int main(){

   cout<<"Enter The Size Of The Array : ";
   int n;
   cin>>n;

   cout<<"\nEnter The Number Of Elements To Initialize : ";
   int l;
   cin>>l;

   Array<int> arr(n,l);

   int ch=0;
   do{
      cout<<"\nMenu : \n"<<"1) Display Array\n2)Append Element\n3)Insert Elem\n4)Delete Elem\n5)Search For An Elem\n6)Reverse Array\n7)End Program";
      cout<<"\nEnter Your Choice : ";
      cin>>ch;

      switch(ch){
         case 1:{
            arr.Display();
            break;
         }
         case 2:{
            arr.AddElem();
            arr.Display();
            break;
         }
         case 3:{
            arr.Insert();
            arr.Display();
            break;
         }
         case 4:{
            arr.Delete();
            arr.Display();
            break;
         }
         case 5:{
            arr.Search();
            break;
         }
         case 6:{
            arr.Reverse();
            break;
         }
      }
   }while(ch<7);

   return 0;

}

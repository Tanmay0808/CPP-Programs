#include<iostream>
using namespace std;

int h1(int x)
{
   return x%10;
}

int h2(int x)
{
   return 7 - (x%7);
}

int mod_hash(int x,int i)
{
    return ((h1(x) + i*h2(x))%10);
}

class DoubleHashing
{
   private:
      int *A;
   public:
      int n;
      DoubleHashing()
      {
         n = 0;
         A = new int[10];
         for (int i=0;i<10;i++)
            A[i] = 0;
      }
      ~DoubleHashing(){delete []A;}
      void insertVal(int data);
      int deleteVal(int data);
      void searchVal(int data);
      bool inkeylimit(){return n < 5 ? true : false;}
};

void DoubleHashing::insertVal(int data)
{
   int ind,i=0;
   n++;
   ind = mod_hash(data,i);
   while (A[ind]!=0){
      i++;
      ind = mod_hash(data,i);
   }
   A[ind] = data;
}

void DoubleHashing::searchVal(int data)
{
   int i=0;
   int ind = mod_hash(data,i);

   if (A[ind]==data){
      cout<<"\nData Value "<<A[ind]<<" Found At Index "<<ind<<endl;
      return;
   }
   else if (A[ind]==0){
      cout<<"\nData Not Found"<<endl;
   }
   else{
      while(A[ind]!=data)
      {
         i++;
         ind = mod_hash(data,i);
         if (A[ind]==0){
            cout<<"\nData Not Found"<<endl;
            return;
         }
      }
      cout<<"\nData Value "<<A[ind]<<" Found At Index "<<ind<<endl;
   }
}

int main()
{
   cout<<"DOUBLE HASHING : -- "<<endl;

   int ch{0},data;
   DoubleHashing L;
   do {
      cout<<"\nMenu :  -- \n1) Insertion \n2) Search Data \n3) Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            if (L.inkeylimit()){
               cout<<"\nEnter Data To Insert : ";
               cin>>data;
               L.insertVal(data);
           }
           else
           {
               cout<<"\nCant Add More Keys, Loading Factor Will Degrade"<<endl;
           }
            break;
         }
         case 2:
         {
            cout<<"\nEnter Data To Be Searched : ";
            cin>>data;
            L.searchVal(data);
            break;
         }
      }
   }while (ch < 3);

   return 0;
}


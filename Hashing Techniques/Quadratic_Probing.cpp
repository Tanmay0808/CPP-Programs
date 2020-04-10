#include<iostream>
using namespace std;

int func_fi(int x)
{
   return x*x;
}

int hash_func(int x)
{
   return x%10;
}

int mod_hash(int x,int i)
{
    return ((hash_func(x) + func_fi(i))%10);
}

class QuadraticProbing
{
   private:
      int *A;
   public:
      int n;
      QuadraticProbing()
      {
         n = 0;
         A = new int[10];
         for (int i=0;i<10;i++)
            A[i] = 0;
      }
      ~QuadraticProbing(){delete []A;}
      void insertVal(int data);
      void searchVal(int data);
      bool inkeylimit(){return n < 5 ? true : false;}
};

void QuadraticProbing::insertVal(int data)
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

void QuadraticProbing::searchVal(int data)
{
   int i=0;
   int ind = mod_hash(data,i);

   if (A[ind]==data){
      cout<<"\nData Value "<<A[ind]<<" Found At Index "<<ind<<endl;
   }
   else if (A[ind] == 0)
   {
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
   cout<<"QUADRATIC PROBING : -- "<<endl;

   int ch{0},data;
   QuadraticProbing L;
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


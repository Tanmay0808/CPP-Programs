#include<iostream>
using namespace std;

class Diagonal
{
   private:
      int n;
      int *A;
   public:
      Diagonal(int n)
      {
         this->n = n;
         A = new int[n];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~Diagonal(){delete []A;}
};

void Diagonal::StoreMatrix()
{
   int x,flg=0;
   cout<<"\nEnter All Elements : "<<endl;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++)
      {
         cin>>x;
         if (i==j)
            A[i-1] = x;
         else if (i!=j && x>0)
            flg=1;
      }
   }
   if (flg)
      cout<<"\nSome Elements Not Belonging To Diagonal Matrix Entered,\nSetting Them To Zero"<<endl;
}

void Diagonal::DisplayMatrix()
{
   cout<<"\nDiagonal Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
     for (int j=1;j<=n;j++)
     {
        if (i==j)
           cout<<A[i-1]<<" ";
        else
           cout<<0<<" ";
     }
     cout<<endl;
   }
}

int main()
{
   cout<<"Enter The Size Of The Square Matrix : ";
   int s;
   cin>>s;

   Diagonal A(s);
   A.StoreMatrix();
   A.DisplayMatrix();

   return 0;
}

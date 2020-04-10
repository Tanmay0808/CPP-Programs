#include<iostream>
using namespace std;

class Toeplitz
{
   private:
      int *A;
      int n;
   public:
      Toeplitz(int n)
      {
         this->n = n;
         A  = new int [2*n - 1];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~Toeplitz()
      {
         delete []A;
      }
};

void Toeplitz::StoreMatrix()
{
   int x;
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         cin>>x;
         if (i<=j)
            A[j - i] = x;
         else if (i > j)
            A[n + (i-j-1)] = x;
      }
   }
}

void Toeplitz::DisplayMatrix()
{
   cout<<"\nToeplitz Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         if (i<=j)
            cout<<A[j-i]<<" ";
         else if (i>j)
            cout<<A[n + (i-j-1)]<<" ";
      }
      cout<<endl;
   }
}

int main()
{
   cout<<"Enter The Size Of The Square Matrix : ";
   int s;
   cin>>s;

   Toeplitz Arr(s);
   Arr.StoreMatrix();
   Arr.DisplayMatrix();

   return 0;
}

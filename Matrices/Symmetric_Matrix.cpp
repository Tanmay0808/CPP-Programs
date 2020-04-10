#include<iostream>
using namespace std;

class Symmetric
{
   private:
      int *A;
      int n;
   public:
      Symmetric(int n)
      {
         this->n = n;
         A = new int[(n*(n+1))/2];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~Symmetric()
      {
         delete []A;
      }
};

void Symmetric::StoreMatrix()
{
   int x;
   cout<<"\nEnter All Elements As In Upper Tri-Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         cin>>x;
         if (i<=j)
            A[((j*(j-1))/2) + (i-1)] = x;
      }
   }
}

void Symmetric::DisplayMatrix()
{
   cout<<"\nSymmetric Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         if (i<=j)
            cout<<A[((j*(j-1))/2) + (i-1)]<<" ";
         else
            cout<<A[((i*(i-1))/2) + (j-1)]<<" ";
      }
      cout<<endl;
   }
}

int main()
{
   cout<<"Enter The Size Of The Square Matrix : ";
   int s;
   cin>>s;

   Symmetric Arr(s);
   Arr.StoreMatrix();
   Arr.DisplayMatrix();

   return 0;
}


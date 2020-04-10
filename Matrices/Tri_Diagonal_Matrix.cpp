#include<iostream>
using namespace std;

class TriDiagonal
{
   private:
      int *A;
      int n;
   public:
      TriDiagonal(int n)
      {
         this->n = n;
         A = new int[3*n - 2];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~TriDiagonal()
      {
         delete []A;
      }
};

void TriDiagonal::StoreMatrix()
{
   int x,flg=0;
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         cin>>x;
         if (i - j == 1)
            A[i-2] = x;
         else if (i - j == 0)
            A[(n-1) + (i-1)] = x;
         else if (i - j == -1)
            A[(2*n-1) + (i-1)] = x;
         else if (x>0)
            flg = 1;
      }
   }
   if (flg)
      cout<<"\nSome Elements Not Belonging To Tri-Diagonal Matrix Entered,\nSetting Them To Zero"<<endl;
}

void TriDiagonal::DisplayMatrix()
{
   cout<<"\nTri-Diagonal Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         if (i - j == 1)
            cout<<A[i-2]<<" ";
         else if (i - j == 0)
            cout<<A[(n-1) + (i-1)]<<" ";
         else if (i - j == -1)
            cout<<A[(2*n-1) + (i-1)]<<" ";
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

   TriDiagonal Arr(s);
   Arr.StoreMatrix();
   Arr.DisplayMatrix();

   return 0;

}

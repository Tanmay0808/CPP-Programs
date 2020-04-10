#include<iostream>
using namespace std;

class LowerTriangular
{
   private:
      int n;
      int *A;
   public:
      LowerTriangular(int n){
         this->n = n;
         A = new int[(n*(n+1))/2];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~LowerTriangular(){delete []A;}
};

void LowerTriangular::StoreMatrix()
{
   int x,flg=0;
   cout<<"\nEnter All Elements : "<<endl;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++)
      {
         cin>>x;
         if (i>=j)
            A[((i*(i-1))/2) + (j-1)] = x;
         else if (i<j && x>0)
            flg=1;
      }

   }
   if (flg)
      cout<<"Some Elements Not Belonging To Lower Tri-Matrix Entered,\nSetting Them To Zero"<<endl;
}

void LowerTriangular::DisplayMatrix()
{
   cout<<"\nLower Triangular Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         if (i<j)
            cout<<0<<" ";
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

   LowerTriangular Arr(s);
   Arr.StoreMatrix();
   Arr.DisplayMatrix();

   return 0;
}

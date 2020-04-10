#include<iostream>
using namespace std;

class UpperTriangle
{
   private:
      int *A;
      int n;
   public:
      UpperTriangle(int n)
      {
         this->n = n;
         A = new int [(n*(n+1))/2];
      }
      void StoreMatrix();
      void DisplayMatrix();
      ~UpperTriangle()
      {
         delete []A;
      }
};

void UpperTriangle::StoreMatrix()
{
   int x,flg=0;
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
      {
         cin>>x;
         if (i<=j)
         {
            A[((j*(j-1))/2) + (i-1)]=x;
         }
         else if (i>j && x>0)
            flg = 1;
      }
   }
   if (flg)
      cout<<"Some Elements Not Belonging To Upper Tri-Matrix Entered,\nSetting Them To Zero"<<endl;
}

void UpperTriangle::DisplayMatrix()
{
   cout<<"\nUpper Triangular Matrix : "<<endl;
   for (int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         if (i<=j)
         {
            cout<<A[((j*(j-1))/2) + (i-1)]<<" ";
         }
         else{
            cout<<0<<" ";
         }
      }
      cout<<endl;
   }
}

int main()
{
   cout<<"Enter The Size Of The Square Matrix : ";
   int s;
   cin>>s;

   UpperTriangle Arr(s);
   Arr.StoreMatrix();
   Arr.DisplayMatrix();

   return 0;
}


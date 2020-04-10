#include<iostream>
using namespace std;

class AdjacencyMatrix
{
   private:
      int **A;
      int n;
   public:
      AdjacencyMatrix(int n)
      {
         this->n = n;
         A = new int *[n+1];
         for (int i=0;i<n+1;i++)
         {
            A[i] = new int[n+1];
         }
         for (int i=0;i<n+1;i++)
            for (int j=0;j<n+1;j++)
               A[i][j] = 0;
      }
      ~AdjacencyMatrix()
      {
         for (int i=0;i<n+1;i++)
         {
            delete []A[i];
         }
         delete []A;
      }
      void insertVal(int i,int j);
      void display();
};

void AdjacencyMatrix::insertVal(int i, int j)
{
   if ((i > 0 && j>0) && (i < n+1 && j < n+1))
      A[i][j] = A[j][i] = 1;
   else
      cout<<"\nInvalid Vertex"<<endl;
}

void AdjacencyMatrix::display()
{
   for (int i=1;i<n+1;i++)
   {
      for (int j=1;j<n+1;j++)
      {
         cout<<A[i][j]<<"  ";
      }
      cout<<endl;
   }
}

int main()
{
   cout<<"GRAPH : --"<<endl;

   cout<<"\nEnter No. Of Vertices : ";
   int n;cin>>n;
   AdjacencyMatrix A(n);
   int ch{0},i,j;
   do{
      cout<<"\nMenu : --\n1) Insert Edge \n2) Display Matrix \n3) Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Pair (V1,V2) Containing Edge : ";
            cin>>i>>j;
            A.insertVal(i,j);
            break;
         }
         case 2:
         {
            cout<<"\nAdjacency Matrix : "<<endl;
            A.display();
            break;
         }
      }
   }while(ch < 3);

   return 0;
}

#include<iostream>
using namespace std;

class CompactList
{
   private:
      int n,e;
      int *A;
   public:
      CompactList(int n, int e)
      {
         this->n = n;
         this->e = e;
         A = new int[n + 2*e + 2];
      }
      ~CompactList(){delete []A;}
      void insertEdge(int i);
      void display();
};

void CompactList::insertEdge(int i)
{
   int ch,j=0;
   A[1] = n+2;
   if ((i>0) && (i<n+1))
   {
      static int st = n+2;
      cout<<"\nEnter Adjacent Vertices Of "<<i<<"  :  ";
      while (j!=-1 && j < n+1){
         cin>>j;
         if (j !=-1)
            A[st++] = j;
      }
      A[i+1] = st;
   }
}

void CompactList::display()
{
   for (int i=1;i<n+2*e+2;i++)
   {
      cout<<A[i]<<"  ";
   }
   cout<<endl;
}

int main()
{
   cout<<"GRAPH : --"<<endl;

   cout<<"\nEnter No. Of Vertices : ";
   int n;cin>>n;
   cout<<"\nEnter NO. Of Edges : ";
   int e;cin>>e;

   CompactList A(n,e);
   int ch{0},i,j;
   do{
      cout<<"\nMenu : --\n1) Insert Vertices \n2) Display Matrix \n3) Exit \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Vertex No. : ";
            cin>>i;
            A.insertEdge(i);
            break;
         }
         case 2:
         {
            cout<<"\nCompact List : "<<endl;
            A.display();
            break;
         }
      }
   }while(ch < 3);

   return 0;
}

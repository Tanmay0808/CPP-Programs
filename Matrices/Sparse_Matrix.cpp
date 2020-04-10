#include<iostream>
using namespace std;

class Sparse
{
   private:
      class Element
      {
         public:
            int row;
            int col;
            int elem;
      };
      int m;
      int n;
      int num;
      Element *e;
  public:
      Sparse(int m,int n,int num)
      {
         this->m = m;
         this->n = n;
         this->num = num;
         e = new Element[num];
      }
      void create();
      void display();
      ~Sparse()
      {
         delete []e;
      }

};

void Sparse::create()
{
   cout<<"\nEnter All Elements : "<<endl;
   for (int i=0;i<num;i++)
   {
      cin>>e[i].row>>e[i].col>>e[i].elem;
   }
}

void Sparse::display()
{
    cout<<"\nSparse Matrix : "<<endl;
    int k=0;
    for (int i=0;i<m;i++)
    {
       for (int j=0;j<n;j++)
       {
           if ((e[k].row-1 == i) && (e[k].col-1 == j))
              cout<<e[k++].elem<<" ";
           else
              cout<<0<<" ";
       }
       cout<<endl;
    }
}

int main()
{
   cout<<"Enter The Dimensions Of Sparse Matrix : ";
   int m,n;
   cin>>m>>n;
   cout<<"\nEnter The Num Of Non-Zero Elements : ";
   int num;
   cin>>num;

   Sparse s(m,n,num);
   s.create();
   s.display();

   return 0;
}

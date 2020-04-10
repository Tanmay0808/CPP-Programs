#include<iostream>
using namespace std;

class Node
{
   public:
      int col;
      int val;
      Node *next;
};

class Sparse
{
   private:
      int m;
      int n;
      Node **A;
   public:
      Sparse(int m,int n){
         this->m = m;
         this->n = n;
         A = new Node *[m];
      }
      ~Sparse()
      {
         for (int i=0;i<m;i++)
         {
            Node *p = A[i];
            while (p!=NULL)
            {
               Node *tmp = p;
               p=p->next;
               delete tmp;
            }
         }
         delete []A;
      }
      void store();
      void display();
};

void Sparse::store()
{
   cout<<"\nEnter All Values : "<<endl;
   for (int i=0;i<m;i++)
   {
      A[i] = NULL;
      cout<<"\nNo. Of Non-Zero Vals In Row "<<i+1<<" : ";
      int k;cin>>k;
      A[i] = new Node;
      cin>>A[i]->col>>A[i]->val;
      A[i]->next = NULL;
      if (k>1)
      {
         Node *last = A[i];
         for (int l=1;l<k;l++)
         {
            Node *tmp = new Node;
            cin>>tmp->col>>tmp->val;
            tmp->next = NULL;
            last->next = tmp;
            last = tmp;
         }
      }
   }
}

void Sparse::display()
{
   for (int i=0;i<m;i++)
   {
      Node *p = A[i];
      for (int j=0;j<n;j++)
      {
         if (j == p->col - 1)
            cout<<p->val<<" ";
         else
            cout<<0<<" ";
         if (p->next)
            p = p->next;
      }
      cout<<endl;
   }
}

int main()
{
   cout<<"Enter Dimensions Of Sparse Matrix : ";
   int m,n;
   cin>>m>>n;

   Sparse s(m,n);
   s.store();
   cout<<"\nSparse Matrix : "<<endl;
   s.display();

   return 0;
}

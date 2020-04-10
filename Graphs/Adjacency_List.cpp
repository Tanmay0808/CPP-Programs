#include<iostream>
using namespace std;

class AdjacencyList
{
   private:
      class Node{
         public:
            int data;
            Node *next;
      };
      int n;
      Node **A;
   public:
      AdjacencyList(int n)
      {
         this->n = n;
         A = new Node *[n+1];
      }
      ~AdjacencyList(){
         for (int i=0;i<n+1;i++)
            A[i] = NULL;
      }
      void insertEdge(int i, int j);
      void display();
};

void AdjacencyList::insertEdge(int i, int j)
{
   if ((i > 0 && j>0) && (i < n+1 && j < n+1)){
      Node *tmp = new Node;
      tmp->data = j;
      tmp->next = NULL;
      if (A[i]==NULL)
      {
         A[i] = tmp;
         return;
      }
      else{
         Node *p = A[i],*q=NULL;
         while (p && p->data < j)
         {
            q = p;
            p = p->next;
         }
         if (p == A[i])
         {
            tmp->next = p;
            p = tmp;
         }
         else{
            tmp->next = q->next;
            q->next = tmp;
         }
      }
   }
   else{
      cout<<"\nInvalid Vertex"<<endl;
   }
}

void AdjacencyList::display()
{
   for (int i=1;i<n+1;i++)
   {
      cout<<"\nVertices Adjacent To  "<<i<<"   :   ";
      Node *p = A[i];
      while(p!=NULL)
      {
         cout<<p->data<<"  ";
         p = p->next;
      }
   }
   cout<<endl;
}

int main()
{
   cout<<"GRAPH : --"<<endl;

   cout<<"\nEnter No. Of Vertices : ";
   int n;cin>>n;
   AdjacencyList A(n);
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
            A.insertEdge(i,j);
            A.insertEdge(j,i);
            break;
         }
         case 2:
         {
            cout<<"\nAdjacency List : "<<endl;
            A.display();
            break;
         }
      }
   }while(ch < 3);

   return 0;
}

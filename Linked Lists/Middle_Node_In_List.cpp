#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class LinkedList{
   private:
      Node *head;
   public:
      LinkedList(){head = NULL;}
      ~LinkedList(){
         while(head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void createList(int n);
      void middleNode();
      void display();
};

void LinkedList::createList(int n)
{
   int data;
   if (head==NULL)
   {
      cout<<"\nEnter Data Value : ";
      cin>>data;
      head = new Node;
      head->data = data;
      head->next = NULL;
   }
   Node *last = head;
   for (int i=1;i<n;i++)
   {
      cout<<"\nEnter Data Value : ";
      cin>>data;
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = NULL;
      last->next = tmp;
      last = tmp;
   }
}

void LinkedList::display()
{
   Node *pt = head;
   while (pt!=NULL)
   {
      cout<<pt->data<<" -> ";
      pt = pt->next;
   }
   cout<<"NULL"<<endl;
}

void LinkedList::middleNode(){
   Node *p,*q;
   p = q = head;
   while (q!=NULL)
   {
      q=q->next;
      if (q){q=q->next;}
      if (q){p=p->next;}
   }
   cout<<"\nMiddle Node Is At : "<<p<<endl<<"Data : "<<p->data<<endl;
}

int main()
{
   LinkedList l;
   cout<<"Enter No. Of Nodes : ";
   int n;cin>>n;
   l.createList(n);
   cout<<"\nLinked List : "<<endl;
   l.display();
   l.middleNode();

   return 0;
}

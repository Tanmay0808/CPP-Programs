#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class LinkedList
{
   public:
      Node *head;
      LinkedList(){head = NULL;}
      ~LinkedList()
      {
         while (head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void createList();
      void display();
      void reverseNodes();
      void reverseRecursion(Node *q, Node *p);
};

void LinkedList::createList()
{
   cout<<"Enter No. Of Nodes : ";
   int n;cin>>n;
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
      pt=pt->next;
   }
   cout<<"NULL"<<endl;
}

void LinkedList::reverseNodes()
{
   Node *p = head,*q=NULL,*r=NULL;
   while (p!=NULL)
   {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
   }
   head = q;
}

void LinkedList::reverseRecursion(Node *q, Node *p)
{
   if (p!=NULL)
   {
      reverseRecursion(p,p->next);
      p->next = q;
   }
   else{
      head = q;
   }
}

int main()
{
   LinkedList l;
   l.createList();
   cout<<"\nLinked List : "<<endl;
   l.display();
   l.reverseNodes();
   cout<<"\nReversed Linked List : "<<endl;
   l.display();
   cout<<"\nReversed Linked List Using Recursion : "<<endl;
   l.reverseRecursion(NULL,l.head);
   l.display();

   return 0;
}


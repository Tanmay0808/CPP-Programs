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
      int len;
      LinkedList(){head = NULL;len=0;}
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
      void reverseElems();
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
      len+=1;
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
      len++;
   }
}

void LinkedList::display()
{
   Node *pt=head;
   while (pt!=NULL)
   {
      cout<<pt->data<<" -> ";
      pt=pt->next;
   }
   cout<<"NULL"<<endl;
}

void LinkedList::reverseElems()
{
   int a[len],i=0;
   Node *p = head;
   while (p!=NULL)
   {
      a[i] = p->data;
      p = p->next;
      i++;
   }
   p = head;i--;
   while (p!=NULL)
   {
      p->data = a[i];
      p=p->next;
      i--;
   }
}

int main()
{
   LinkedList l;
   l.createList();
   cout<<"\nLinked List : "<<endl;
   l.display();
   l.reverseElems();
   cout<<"\nReversed Linked List : "<<endl;
   l.display();

   return 0;
}

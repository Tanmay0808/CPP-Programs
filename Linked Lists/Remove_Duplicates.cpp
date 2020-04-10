#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class LinkedList
{
   private:
      Node *head;
   public:
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
      void removeDuplicates();
};

void LinkedList::createList()
{
   cout<<"Enter No. Of Nodes : ";
   int n;cin>>n;
   cout<<"\nEnter Data Value : ";
   int data;
   cin>>data;
   if (head == NULL)
   {
       head = new Node;
       head->data = data;
       head->next = NULL;
   }
   if (n>0)
   {
      Node *last = head;
      for (int i=1;i<n;i++)
      {
         cout<<"\nEnter Data Value : ";
         cin>>data;
         Node *tmp = new Node;
         tmp->data = data;
         last->next = tmp;
         last = tmp;
      }
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

void LinkedList::removeDuplicates()
{
   Node *q = head;
   Node *p = head->next ;
   while (p!=NULL)
   {
      if (p->data != q->data)
      {
         q = p;
         p = p->next;
      }else{
         q->next = p->next;
         delete p;
         p = q->next;
      }
   }
}

int main()
{
   LinkedList l;
   l.createList();
   cout<<"\nLinked List : "<<endl;
   l.display();
   l.removeDuplicates();
   cout<<"\nLinked List After Removal Of Duplicates : "<<endl;
   l.display();

   return 0;
}


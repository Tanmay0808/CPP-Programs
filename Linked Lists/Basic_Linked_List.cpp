#include<iostream>
using namespace std;

class Node
{
   public:
      int data;
      Node *next;
};

class LinkedList
{
   public:
      Node *head;
      LinkedList(){head = NULL;}
      ~LinkedList(){
         while (head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void createList();
      void display();
      void recursiveDisplay(Node *pt);
};

void LinkedList::createList()
{
   cout<<"Enter NO. Of Nodes : ";
   int n;cin>>n;
   int data;
   head = new Node;
   Node *tmp,*last;
   cout<<"\nEnter Data Value : ";
   cin>>data;
   head->data = data;
   head->next = NULL;
   last = head;
   for (int i=1;i<n;i++)
   {
      tmp = new Node;
      cout<<"\nEnter Data Value : ";
      cin>>data;
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
   cout<<"NULL"<<endl;;
}

void LinkedList::recursiveDisplay(Node *pt)
{
   if (pt!=NULL)
   {
      cout<<pt->data<<" -> ";
      recursiveDisplay(pt->next);
   }
   else{
      cout<<"NULL"<<endl;
   }
}

int main()
{
   LinkedList l;
   l.createList();
   cout<<"\nLinked List Is : "<<endl;
   l.display();

   cout<<"\nDisplaying Linked List Using Recursion : "<<endl;
   l.recursiveDisplay(l.head);

   return 0;
}

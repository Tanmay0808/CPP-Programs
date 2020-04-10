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
}third;

void LinkedList::createList()
{
   cout<<"\nEnter No. Of Nodes : ";
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

void mergeLists(Node *pt1, Node *pt2)
{
   Node *last;
   if (pt1->data < pt2->data){
      third.head = last = pt1;
      pt1=pt1->next;
      last->next = NULL;
   }
   else{
      third.head = last = pt2;
      pt2=pt2->next;
      last->next = NULL;
   }
   while (pt1!=NULL && pt2!=NULL)
   {
      if (pt1->data < pt2->data)
      {
         last->next = pt1;
         last=pt1;
         pt1 = pt1->next;
         last->next = NULL;
      }
      else
      {
         last->next = pt2;
         last=pt2;
         pt2 = pt2->next;
         last->next = NULL;
      }
   }
   while (pt1!=NULL)
   {
      last->next = pt1;
      last = pt1;
      pt1=pt1->next;
      last->next = NULL;
   }
   while (pt2!=NULL)
   {
      last->next = pt2;
      last = pt2;
      pt2=pt2->next;
      last->next = NULL;
   }
}

int main()
{
   LinkedList l1,l2;
   cout<<"First Linked List : ";
   l1.createList();

   cout<<"\nSecond Linked List : ";
   l2.createList();

   cout<<"\nLinked List 1 : "<<endl;
   l1.display();
   cout<<"\nLinked List 2 : "<<endl;
   l2.display();

   mergeLists(l1.head,l2.head);
   cout<<"\nMerged Linked List : "<<endl;
   third.display();

   return 0;
}



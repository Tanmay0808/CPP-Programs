#include<iostream>
#include<limits.h>
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
      void addNode(int data);
      void displayList();
      void maxElem();
      void searchNode();
      Node * searchNodeRecursion(Node *pt, int data);
      int maxElemRecursion(Node *pt);
};

void LinkedList::addNode(int data)
{
   if (head == NULL)
   {
      head = new Node;
      head->data = data;
      head->next = NULL;
   }
   else
   {
      Node *last = head;
      while (last->next!=NULL){last=last->next;}
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = NULL;
      last->next = tmp;
      last = tmp;
   }
}

void LinkedList::displayList()
{
   Node *pt = head;
   cout<<"\nLinked List : "<<endl;
   while (pt!=NULL)
   {
      cout<<pt->data<<" -> ";
      pt=pt->next;
   }
   cout<<"NULL"<<endl;
}

void LinkedList::maxElem()
{
   Node *pt = head;
   int max = INT_MIN;
   while (pt!=NULL)
   {
      if (max < pt->data)
         max = pt->data;
      pt=pt->next;

   }
   cout<<"\nMaximum Element : "<<max<<endl;
}

void LinkedList::searchNode()
{
   Node *pt = head;
   cout<<"\nEnter Data To Be Searched : ";
   int data;cin>>data;
   while (pt!=NULL)
   {
      if (pt->data == data){
         cout<<"\nData Present In Linked List At : "<<pt<<endl;
         return;
      }
      pt=pt->next;
   }
   cout<<"\nData Not Present In Linked List"<<endl;
}

Node * LinkedList::searchNodeRecursion(Node *pt,int data)
{
   if (pt==NULL)
      return NULL;
   if (pt->data == data)
      return pt;
   return searchNodeRecursion(pt->next,data);
}

int LinkedList:: maxElemRecursion(Node *pt)
{
   int x=0;
   if (pt==NULL)
      return INT_MIN;
   x = maxElemRecursion(pt->next);
   return x > pt->data ? x : pt->data;
}

int main()
{
   int ch;
   LinkedList l;
   do{
      cout<<"\nMenu : \n1)Add Node \n2)Display List \n3)Find Max Elem \n4)Find Max Elem - Recursion \n5)Search For An Element \n6)Search For Elem - Recursion \n7)Exit\nEnter Choice : ";
      cin>>ch;
      switch (ch)
      {
         case 1:
         {
            cout<<"\nEnter Data Value : ";
            int data;
            cin>>data;
            l.addNode(data);
            break;
         }
         case 2:
         {
            l.displayList();
            break;
         }
         case 3:
         {
            l.maxElem();
            break;
         }
         case 4:
         {
            cout<<"\nMax Element Using Recursion : "<<l.maxElemRecursion(l.head)<<endl;
            break;
         }
         case 5:
         {
            l.searchNode();
            break;
         }
         case 6:
         {
            cout<<"\nEnter Data To Be Searched : ";
            int data;
            cin>>data;
            Node *p = l.searchNodeRecursion(l.head,data);
            if (p!=NULL)
               cout<<"\nData Present In Linked List At : "<<p<<endl;
            else
               cout<<"\nData Not Present In Linked List"<<endl;
            break;
         }
      }
   }while(ch<7);

   return 0;
}

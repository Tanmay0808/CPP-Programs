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
      bool checkSorted();
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
   cout<<"\nLinked List : "<<endl;
   while (pt!=NULL)
   {
      cout<<pt->data<<" -> ";
      pt=pt->next;
   }
   cout<<"NULL"<<endl;
}

bool LinkedList::checkSorted()
{
   Node *pt = head;
   int x = INT_MIN;
   while (pt!=NULL)
   {
      if (pt->data < x)
         return false;
      x = pt->data;
      pt=pt->next;
   }
   return true;
}

int main()
{
   LinkedList l;
   l.createList();
   l.display();
   if (l.checkSorted())
      cout<<"\nList Is Sorted"<<endl;
   else
      cout<<"\nList Is Not Sorted"<<endl;

   return 0;
}

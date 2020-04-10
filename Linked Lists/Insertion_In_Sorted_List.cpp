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
      void insertNode(int data);
      void display();
};

void LinkedList::insertNode(int data)
{
   Node *tmp = new Node,*q=NULL;
   tmp->data = data;
   tmp->next = NULL;

   if (head == NULL)
   {
      head = tmp;
      return;
   }
   else{
      Node *p=head;
      while (p && p->data < data)
      {
         q = p;
         p = p->next;
      }
      if (p == head)
      {
         tmp->next = head;
         head = tmp;
      }
      else{
         tmp->next = q->next;
         q->next = tmp;
      }
   }
}

void LinkedList::display()
{
    Node *pt = head;
    while(pt!=NULL)
    {
       cout<<pt->data<<" -> ";
       pt=pt->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
   int ch;
   LinkedList l;
   do{
      cout<<"\nMenu : -- \n1)Insertion \n2)Display List \n3)Exit\nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            int data;
            cin>>data;
            l.insertNode(data);
            break;
         }
         case 2:
         {
            cout<<"\nLinked List Is : "<<endl;
            l.display();
            break;
         }
      }
   }while(ch<3);

   return 0;
}

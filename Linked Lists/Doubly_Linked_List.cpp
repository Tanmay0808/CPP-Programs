#include<iostream>
using namespace std;

class Node
{
   public:
      Node *prev;
      int data;
      Node *next;
};

class Doubly
{
   private:
      Node *head;
   public:
      Doubly(){head = NULL;}
      ~Doubly(){
         while (head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void insertNode(int data, int pos);
      void display();
      void deleteNode(int pos);
      void reverseList();
};

void Doubly::insertNode(int data, int pos=0)
{
   if (head == NULL)
   {
      head = new Node;
      head->prev = NULL;
      head->data = data;
      head->next = NULL;
      return;
   }
   else if (pos == 0)
   {
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = head;
      tmp->prev = NULL;
      head->prev = tmp;
      head = tmp;
   }
   else
   {
      Node *last = head;
      for (int i=0;i<pos-1;i++)
      {
         last = last->next;
      }
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = last->next;
      tmp->prev = last;
      if(last->next)
         last->next->prev = tmp;
      last->next = tmp;
   }
}

void Doubly::deleteNode(int pos = -1)
{
   if (head==NULL)
      return;
   if (pos == -1)
   {
      Node *p = head;
      head = head->next;
      head->prev = NULL;
      delete p;
   }
   else
   {
      Node *last = head;
      for (int i=0;i<pos-1;i++)
      {
         last = last->next;
      }
      last->prev->next = last->next;
      if (last->next)
         last->next->prev = last->prev;
      delete last;
   }
}

void Doubly::reverseList()
{
   Node *pt = head;
   while (pt)
   {
      Node *tmp = pt->next;
      pt->next=pt->prev;
      pt->prev = tmp;
      pt = pt->prev;
      if (pt!=NULL && pt->next == NULL)
         head = pt;
   }
}

void Doubly::display()
{
   Node *pt = head;
   cout<<"NULL <-> ";
   while (pt!=NULL)
   {
      cout<<pt->data<<" <-> ";
      pt=pt->next;
   }
   cout<<"NULL"<<endl;
}

int main(){
   Doubly l;
   int ch{0},c{0};
   do{
      cout<<"\nMenu : \n1)Insertion \n2)Deletion \n3)Display \n4)Reverse List \n5)Exit\nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            int data;cin>>data;
            cout<<"\n1)At Front \n2)At Some Position\nEnter Choice : ";
            cin>>c;
            if (c==1)
               l.insertNode(data);
            else{
               int x;
               cout<<"\nEnter Position : ";
               cin>>x;
               l.insertNode(data,x);
            }
            break;
         }
         case 2:
         {
            cout<<"\n1)From Front \n2)From Some Position\nEnter Choice : ";
            cin>>c;
            if (c==1)
               l.deleteNode();
            else{
               int x;
               cout<<"\nEnter Position : ";
               cin>>x;
               l.deleteNode(x);
            }
            break;
         }
         case 3:
         {
            cout<<"\nDoubly Linked List : "<<endl;
            l.display();
            break;
         }
         case 4:
         {
            cout<<"\nReversed Doubly Linked List : "<<endl;
            l.reverseList();
            l.display();
            break;
         }
      }
   }while(ch<5);
   return 0;
}

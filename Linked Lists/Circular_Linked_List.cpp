#include<iostream>
using namespace std;

class Node
{
   public:
      int data;
      Node *next;
};

class Circular
{
   private:
      Node *head;
   public:
      Circular(){head = NULL;}
      ~Circular()
      {
         while (head!=NULL)
         {
            deleteNode(-1);
            if (head->next == head)
            {
               delete head;
               head=NULL;
            }
         }
      }
      void insertNode(int data, int pos);
      void deleteNode(int pos);
      void display();
      void displayRecursion(Node *pt);
};

void Circular::insertNode(int data, int pos=0)
{
   if (head == NULL)
   {
      head = new Node;
      head->data = data;
      head->next = head;
      return;
   }
   else if (pos == 0)
   {
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = head;
      Node *p = head;
      while (p->next != head){p=p->next;}
      p->next = tmp;
   }
   else
   {
      Node *p = head;
      Node *tmp = new Node;
      tmp->data = data;
      for (int i=0;i<pos-1;i++)
      {
         p = p->next;
      }
      tmp->next = p->next;
      p->next = tmp;
   }
}

void Circular::deleteNode(int pos=-1)
{
   if (head == NULL)
      return;
   if (pos == -1)
   {
      Node *p = head;
      while (p->next !=head)
      {
         p = p->next;
      }
      p->next = head->next;
      delete head;
      head = p->next;
   }
   else
   {
      Node *p = head,*q=NULL;
      for (int i=0;i<pos-1;i++)
      {
         q = p;
         p = p->next;
      }
      q->next = p->next;
      delete p;
   }
}

void Circular::display()
{
   Node *pt = head;
   do{
      cout<<pt->data<<" -> ";
      pt = pt->next;
   }while (pt!=head);
   cout<<" . . . . Repeat"<<endl;
}

int main()
{
   Circular l;
   int ch{0},c{0};
   do{
       cout<<"\nMenu \n1)Insertion \n2)Deletion \n3)Display \n4)Exit\nEnter Choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1:
          {
             cout<<"\nEnter Data To Insert : ";
             int data;cin>>data;
             cout<<"\n1)Before Head \n2)At Random Position \nEnter Choice : ";
             cin>>c;
             if (c == 1)
                l.insertNode(data,0);
             else if (c == 2){
                int x;
                cout<<"\nEnter Position : ";
                cin>>x;
                l.insertNode(data,x);
             }
             break;
          }
          case 2:
          {
             cout<<"\n1)Before Head \n2)From Random Position \nEnter Choice : ";
             cin>>c;
             if (c == 1)
                l.deleteNode();
             else if (c == 2){
                int x;
                cout<<"\nEnter Position : ";
                cin>>x;
                l.deleteNode(x);
             }
             break;
          }
          case 3:
          {
             cout<<"\nCircular Linked List : "<<endl;
             l.display();
             break;
          }
       }
   }while(ch<4);

   return 0;
}

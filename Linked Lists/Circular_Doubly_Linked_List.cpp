#include<iostream>
using namespace std;

class Node{
   public:
      Node *prev;
      int data;
      Node *next;
};

class CircularDoubly
{
   private:
      Node *head;
   public:
      CircularDoubly(){head = NULL;}
      ~CircularDoubly()
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
      };
      void insertNode(int data,int pos);
      void deleteNode(int pos);
      void display();
};

void CircularDoubly::insertNode(int data, int pos=0)
{
   if (head == NULL)
   {
      head = new Node;
      head->data = data;
      head->prev = head->next = head;
      return;
   }
   else if (pos == 0)
   {
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = head;
      tmp->prev = head->prev;
      head->prev->next = tmp;
      head->prev = tmp;
   }
   else{
      Node *last = head;
      for (int i=0;i<pos-1;i++)
      {
         last = last->next;
      }
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = last->next;
      tmp->prev = last;
      last->next->prev = tmp;
      last->next = tmp;
   }
}

void CircularDoubly::deleteNode(int pos = -1)
{
   if (head == NULL)
      return;

   if (pos == -1)
   {
      Node *tmp = head;
      head = head->next;
      head->prev = tmp->prev;
      tmp->prev->next = head;
      delete tmp;
   }
   else
   {
      Node *last = head;
      for (int i=0;i<pos-1;i++)
      {
         last = last->next;
      }
      last->prev->next = last->next;
      if(last->next)
         last->next->prev = last->prev;
      delete last;
   }
}

void CircularDoubly::display()
{
   Node *pt = head;
   do{
      cout<<pt->data<<" <-> ";
      pt=pt->next;
   }while(pt!=head);
   cout<<" . . . . Repeat"<<endl;
}

int main()
{
   CircularDoubly l;
   int ch{0},c{0};
   do{
      cout<<"\nMenu : \n1)Insertion \n2)Deletion \n3)Display \n4)Exit\nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            int data;
            cin>>data;
            cout<<"\n1)Before Head \n2)At Some Position \nEnter Choice : ";
            cin>>c;
            if (c==1)
               l.insertNode(data);
            else if (c==2){
               int x;
               cout<<"\nEnter Position : ";
               cin>>x;
               l.insertNode(data,x);
            }
            break;
         }
         case 2:
         {
            cout<<"\n1)Delete Head \n2)Delete At Some Position \nEnter Choice : ";
            cin>>c;
            if (c==1)
               l.deleteNode();
            else if (c==2)
            {
               int x;
               cout<<"Enter Position : ";
               cin>>x;
               l.deleteNode(x);
            }
            break;
         }
         case 3:
         {
            cout<<"\nCircular Doubly Linked List : "<<endl;
            l.display();
            break;
         }
      }
   }while (ch<4);
   return 0;
}

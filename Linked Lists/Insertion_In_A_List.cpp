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
      void insertNode(int data, int pos);
      void deleteNode(int pos);
      void display();
};

void LinkedList::insertNode(int data,int pos=-1)
{
   if (head == NULL)
   {
      head = new Node;
      head->data = data;
      head->next = NULL;
      return;
   }
   Node *tmp = new Node;
   if (pos == 0)
   {
      tmp->data = data;
      tmp->next = head;
      head = tmp;
   }
   else if (pos == -1){
      Node *last = head;
      while (last->next!=NULL){last = last->next;}
      tmp->data = data;
      tmp->next = NULL;
      last->next = tmp;
      last = tmp;
   }
   else
   {
      Node *last = head;
      for (int i=0;i<pos-1;i++)
      {
         last = last->next;
      }
      tmp->data = data;
      tmp->next = last->next;
      last->next = tmp;
      last=tmp;
   }
}

void LinkedList::deleteNode(int pos=1)
{
   if (head == NULL)
      return;

   if (pos==1)
   {
      Node *tmp = head;
      head = tmp->next;
      delete tmp;
   }
   else if(pos==-1)
   {
      Node *p=head,*q=NULL;
      while(p->next!=NULL)
      {
         q = p;
         p = p->next;
      }
      q->next = NULL;
      delete p;
   }
   else{
      Node *p=head,*q=NULL;
      for (int i=0;i<pos-1 && p;i++)
      {
         q = p;
         p = p->next;
      }
      q->next = p->next;
      delete p;
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
   cout<<"NULL"<<endl;
}

int main()
{
   int ch{0},c{0};
   LinkedList l;
   do{
      cout<<"\nMenu : \n1)Insertion \n2)Deletion \n3)Display Linked List \n4)Exit\nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"\nEnter Data To Insert : ";
            int data;
            cin>>data;
            cout<<"\n1)At Front \n2)At End \n3)At Some Position \nEnter Choice : ";
            cin>>c;
            if (c == 1)
                l.insertNode(data,0);
            else if(c == 2)
                l.insertNode(data,-1);
            else{
                cout<<"\nEnter Position : ";
                int x;
                cin>>x;
                l.insertNode(data,x);
            }
            break;
         }
         case 2:
         {
            cout<<"\n1)From Front \n2)From End \n3)From Some Position \nEnter Choice : ";
            cin>>c;
            if (c == 1)
                l.deleteNode();
            else if(c == 2)
                l.deleteNode(-1);
            else{
                cout<<"\nEnter Position : ";
                int x;
                cin>>x;
                l.deleteNode(x);
            }
            break;
         }
         case 3:
         {
            cout<<"\nLinked List Is : "<<endl;
            l.display();
            break;
         }
      }
   }while(ch<4);

    return 0;
}

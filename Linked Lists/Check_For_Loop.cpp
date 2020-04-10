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
      int len;
   public:
      LinkedList(){head = NULL;len=0;}
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
      bool checkLoop();
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
      len+=1;
   }
   Node *last = head,*val;
   for (int i=1;i<n;i++)
   {
      cout<<"\nEnter Data Value : ";
      cin>>data;
      Node *tmp = new Node;
      tmp->data = data;
      tmp->next = NULL;
      if (i==n-3)
         val = tmp;
      last->next = tmp;
      last = tmp;
      len++;
   }
   cout<<"\nWant To Have Loop For Testing (y/n) : ";
   char ch;
   cin>>ch;
   if (ch=='y')
      last->next = val;
}

bool LinkedList::checkLoop()
{
   Node *p,*q;
   p=q=head;
   if (head == NULL)
      return false;
   do{
        q = q->next;
        p = p->next;
        p = p->next!=NULL?p->next:NULL;
        if (p==q)
           return true;
    }while (p&&q&&p->next);
    return false;
}

void LinkedList::display()
{
   Node *pt=head;
   if (!checkLoop())
   {
      cout<<"\nLinear Linked List : "<<endl;
      while(pt!=NULL)
      {
         cout<<pt->data<<" -> ";
         pt=pt->next;
      }
      cout<<"NULL"<<endl;
   }
   else
   {
      cout<<"\nLinked List With Loop : "<<endl;
      for (int i=0;i<len;i++)
      {
         cout<<pt->data<<" -> ";
         pt=pt->next;
      }
      cout<<pt->data<<"  ->  . . . . .Loop"<<endl;
   }
}

int main()
{
   LinkedList l;
   l.createList();
   if (l.checkLoop())
      cout<<"\nLinked List Contains Loop "<<endl;
   else
      cout<<"\nLinked List Does Not Contain Loop"<<endl;
   l.display();

   return 0;
}

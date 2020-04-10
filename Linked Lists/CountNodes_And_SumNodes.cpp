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
      void addNode(int data);
      void display();
      int displayLength();
      int lengthRecursion(Node *pt);
      int sumNodes();
      int sumRecursion(Node *pt);
};


void LinkedList::addNode(int data)
{
   Node *last;
   if (head == NULL){
      head = new Node;
      head->data = data;
      head->next = NULL;
   }
   else
   {
      last = head;
      while (last->next!=NULL){last=last->next;}
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
      pt = pt->next;
   }
   cout<<"NULL"<<endl;
}

int LinkedList::displayLength()
{
   Node *pt = head;
   int cnt=0;
   while (pt!=NULL)
   {
      cnt++;
      pt = pt->next;
   }
   return cnt;
}

int LinkedList::lengthRecursion(Node *pt)
{
   if (pt==NULL)
   {
      return 0;
   }
   return lengthRecursion(pt->next) + 1;
}

int LinkedList::sumNodes()
{
   Node *pt = head;
   int sum=0;
   while (pt!=NULL)
   {
      sum += pt->data;
      pt = pt->next;
   }
   return sum;
}

int LinkedList::sumRecursion(Node *pt)
{
   if (pt==NULL)
      return 0;
   return sumRecursion(pt->next) + pt->data;
}

int main()
{
   int data,ch;
   LinkedList l;
   do{
      cout<<"\nMenu : \n"<<"1)Add Node \n2)Display List \n3)Display No. Of Nodes \n4)No. Of Nodes Using Recursion \n5)Calculate Sum \n6)Sum Using Recursion \n7)Exit\n"<<"Enter Choice : ";
      cin>>ch;

      switch (ch)
      {
         case 1:
         {
            cout<<"\nEnter Data Value : ";
            cin>>data;
            l.addNode(data);
            break;
         }
         case 2:
         {
            cout<<"\nLinked List Is : "<<endl;
            l.display();
            break;
         }
         case 3:
         {
            cout<<"\nNo. Of Nodes : "<<l.displayLength()<<endl;
            break;
         }
         case 4:
         {
            cout<<"\nNo. Of Nodes Using Recursion : "<<l.lengthRecursion(l.head)<<endl;
            break;
         }
         case 5:
         {
            cout<<"\nSum : "<<l.sumNodes()<<endl;
            break;
         }
         case 6:
         {
            cout<<"\nSum Using Recursion : "<<l.sumRecursion(l.head)<<endl;
         }
      }
    }while (ch<7);

   return 0;
}

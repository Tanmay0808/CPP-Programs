#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class Queue
{
   private:
      Node *head;
      int front;
      int rear;
      int size;
   public:
      Queue(int n)
      {
         head = NULL;
         front = rear = -1;
         size = n;
      }
      ~Queue()
      {
         while(head)
         {
            Node *tmp = head;
            head = head->next;
            delete tmp;
         }
      }
      void enqueue();
      void dequeue();
      void display();
      void frontVal();
      void rearVal();
      bool isEmpty(){return (head==NULL) ? true : false;}
      bool isFull(){return (rear == size-1) ? true : false;}
};

void Queue::enqueue()
{
   static Node *last;
   if(isFull()){
      cout<<"\nQUEUE FULL"<<endl;
      return;
   }

   cout<<"\nEnter Data To Enqueue : ";
   int data;cin>>data;
   Node *tmp = new Node;
   tmp->data = data;
   tmp->next = NULL;
   if (head == NULL)
   {
      head = last = tmp;
      rear++;front++;
   }
   else{
      last->next = tmp;
      last = tmp;
      rear++;
   }
}

void Queue::dequeue()
{
   if (isEmpty())
   {
      cout<<"\nQUEUE EMPTY"<<endl;
   }
   else{
      Node *tmp = head;
      head = head->next;
      cout<<"\nDequeued Data : "<<tmp->data<<endl;
      delete tmp;
      front = (front < size-1) ? front + 1 : size-1;
   }
}

void Queue::display()
{
   if (isEmpty())
      cout<<"\nQueue Is Empty"<<endl;
   else{
      Node *p = head;
      cout<<"\nFront ->  ";
      while(p!=NULL)
      {
         cout<<p->data<<"  ";
         p = p->next;
      }
      cout<<"<- Rear"<<endl;
   }
}

void Queue::frontVal()
{
   if (!isEmpty())
      cout<<"\nFront : "<<front<<"\nData At Front : "<<head->data<<endl;
   else{
      front = rear = -1;
      cout<<"\nFront : "<<front<<"\nQueue Is Empty "<<endl;
   }
}

void Queue::rearVal()
{
   if (!isEmpty()){
      Node *p = head;
      for (int i=front;i<rear;i++){p = p->next;}
      cout<<"\nRear : "<<rear<<"\nData At Rear : "<<p->data<<endl;
   }
   else{
      front = rear = -1;
      cout<<"\nRear : "<<rear<<"\nQueue Is Empty "<<endl;
   }
}


int main()
{
   int ch{0};
   cout<<"Enter The Size Of The Queue : ";
   int n;cin>>n;

   Queue q(n);
   do{
      cout<<"\nMenu :- \n1)ENQUEUE \n2)DEQUEUE \n3)FRONT \n4)REAR \n5)DISPLAY \n6)EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1:
        {
           q.enqueue();
           break;
        }
        case 2:
        {
           q.dequeue();
           break;
        }
        case 3:
        {
           q.frontVal();
           break;
        }
        case 4:{
           q.rearVal();
           break;
        }
        case 5:
        {
           cout<<"\nQueue : "<<endl;
           q.display();
           break;
        }
      }
   }while (ch<6);

   return 0;
}

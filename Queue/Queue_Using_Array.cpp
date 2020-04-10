#include<iostream>
using namespace std;

class Queue
{
   private:
      int front;
      int rear;
      int size;
      int *A;
   public:
      Queue(int n)
      {
         front = rear = -1;
         size = n;
         A = new int[n];
      }
      ~Queue(){delete []A;}
      void enqueue(int data);
      int dequeue();
      void display();
      void frontVal();
      void rearVal();
      bool isEmpty(){return (front == rear) ? true : false;}
      bool isFull(){return (rear == size-1) ? true : false;}
};

void Queue::enqueue(int data)
{
   A[++rear] = data;
}

int Queue::dequeue()
{
   return A[++front];
}

void Queue::frontVal()
{
   if (!isEmpty())
      cout<<"\nFront : "<<front<<"\nData At Front : "<<A[front]<<endl;
   else
      cout<<"\nFront : "<<front<<"\nQueue Is Empty"<<endl;
}

void Queue::rearVal()
{
   if(!isEmpty())
      cout<<"\nRear : "<<rear<<"\nData At Rear : "<<A[rear]<<endl;
   else
      cout<<"\nRear : "<<rear<<"\nQueue Is Empty"<<endl;
}

void Queue::display()
{
   if (!isEmpty()){
      int p = front;
      cout<<"\nFront ->  ";
      while(p!=rear)
      {
         cout<<A[++p]<<"  ";
      }
      cout<<"<- Rear"<<endl;
   }
   else{
      cout<<"\nEmpty Queue"<<endl;
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
           if(!q.isFull()){
              cout<<"\nEnter Data To Enqueue : ";
              int data;cin>>data;
              q.enqueue(data);
           }
           else
              cout<<"\nQUEUE FULL"<<endl;
           break;
        }
        case 2:
        {
           if (!q.isEmpty())
           {
              cout<<"\nDequeued Data : "<<q.dequeue()<<endl;
           }
           else
              cout<<"\nEMPTY QUEUE"<<endl;
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

#include<iostream>
using namespace std;

class CircularQueue
{
   private:
      int size;
      int front;
      int rear;
      int *A;
   public:
      CircularQueue(int n)
      {
         size = n;
         front = rear = 0;
         A = new int[n];
      }
      ~CircularQueue(){delete []A;}
      void enqueue();
      void dequeue();
      void display();
      bool isEmpty(){return (front == rear) ? true : false;}
      bool isFull(){return (front == ((rear + 1)%size)) ? true : false;}
};

void CircularQueue::enqueue()
{
   if (isFull())
      cout<<"\nQUEUE FULL"<<endl;
   else{
      cout<<"\nEnter Data To Enqueue : ";
      int data;cin>>data;
      rear = (rear + 1)%size;
      A[rear] = data;
   }
}

void CircularQueue::dequeue()
{
   if(isEmpty())
      cout<<"\nQUEUE EMPTY"<<endl;
   else{
      front = (front + 1)%size;
      cout<<"\nDequeued Data : "<<A[front]<<endl;
   }
}

void CircularQueue::display()
{
   if (!isEmpty()){
      int p = front + 1;
      while (p != rear)
      {
         cout<<A[p]<<" ";
         p = (p+1)%size;
      }
      cout<<A[p]<<" . . . Repeat"<<endl;
   }
   else{
     cout<<"\nQueue Is Empty"<<endl;
   }
}

int main()
{
   int ch{0};
   cout<<"Enter The Size Of The Queue : ";
   int n;cin>>n;

   CircularQueue q(n);
   do{
      cout<<"\nMenu :- \n1)ENQUEUE \n2)DEQUEUE \n3)DISPLAY \n4)EXIT \nEnter Choice : ";
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
           cout<<"\nCircular Queue : "<<endl;
           q.display();
           break;
        }
      }
   }while (ch<4);

   return 0;
}

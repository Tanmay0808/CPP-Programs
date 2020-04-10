#include<iostream>
using namespace std;

class PriorityQueue
{
   private:
      int size;
      int front;
      int rear;
      int *A;
   public:
      PriorityQueue(int n)
      {
         size = n;
         front = rear = -1;
         A = new int[n];
      }
      ~PriorityQueue(){delete []A;}
      void enqueue(int data);
      void dequeue();
      void display();
      bool isEmpty(){return (front == rear) ? true : false;}
      bool isFull(){return (rear == size - 1) ? true : false;}
};

void PriorityQueue::enqueue(int data)
{
   if(isFull())
      cout<<"\nQueue Is Full"<<endl;
   else{
      A[++rear] = data;
   }
}

void PriorityQueue::dequeue()
{
   if(isEmpty()){
      front = rear = -1;
      cout<<"\nQueue Is Empty"<<endl;
   }
   else{
      cout<<"\nDequeued Data : "<<A[++front]<<endl;
   }
}

void PriorityQueue::display()
{
   if (isEmpty())
      cout<<"\nQueue Is Empty"<<endl;
   else{
      int p = front+1;
      while(p!=rear)
      {
         cout<<A[p]<<"  ";
         p++;
      }
      cout<<A[p]<<endl;
   }
}

int main()
{
   PriorityQueue *P[3];
   int ch{0};
   for (int i=0;i<3;i++)
   {
      cout<<"Enter Size Of Queue "<<i+1<<" : ";
      int n;cin>>n;
      P[i] = new PriorityQueue(n);
      cout<<endl;
   }

   do{
      cout<<"\nMenu :- \n1)ENQUEUE \n2)DEQUEUE \n3)DISPLAY \n4)EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1:
        {
           cout<<"\nEnter Data To Enqueue : ";
           int data;cin>>data;
           cout<<"\nEnter Priority : ";
           int c;cin>>c;
           if (c==1)
              P[0]->enqueue(data);
           else if(c==2)
              P[1]->enqueue(data);
           else if (c==3)
              P[2]->enqueue(data);
           else
              cout<<"\nInvalid Priority"<<endl;
           break;
        }
        case 2:
        {
           if (!P[0]->isEmpty())
              P[0]->dequeue();
           else if( P[0]->isEmpty()  &&  !P[1]->isEmpty())
              P[1]->dequeue();
           else
              P[2]->dequeue();
           break;
        }
        case 3:
        {
           for (int i=0;i<3;i++)
           {
              cout<<"\nQueue "<<i+1<<"  :  "<<endl;
              P[i]->display();
           }
           break;
        }
      }
   }while (ch<4);

   ///Deleting Memory Allocated To P[0],P[1] &P[2]
   for (int i=0;i<3;i++)
   {
      delete P[i];
   }
   return 0;
}

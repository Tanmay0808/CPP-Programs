#include<iostream>
using namespace std;

class DeQueue
{
   private:
      int size;
      int front;
      int rear;
      int *A;
   public:
      DeQueue(int n){
         size = n;
         front = rear = -1;
         A = new int[n];
      }
      ~DeQueue(){delete []A;}
      void insertFront();
      void insertRear();
      void deleteFront();
      void deleteRear();
      void display();
};

void DeQueue::insertFront()
{
   if (front == -1)
      cout<<"No Space At Front"<<endl;
   else{
      cout<<"\nEnter Data To Insert At Front : ";
      int data;cin>>data;
      A[front--] = data;
   }
}

void DeQueue::insertRear()
{
   if (rear == size-1)
   {
      cout<<"\nQueue Is Full, Cant Insert At Rear"<<endl;
   }
   else{
      cout<<"\nEnter Data To Insert At Rear : ";
      int data;cin>>data;
      A[++rear]  = data;
   }
}

void DeQueue::deleteFront()
{
   if (front == rear)
      cout<<"\nQueue Is Empty"<<endl;
   else{
      cout<<"\nDequeued Data : "<<A[++front]<<endl;
   }
}

void DeQueue::deleteRear()
{
   if (front == rear)
      cout<<"\nQueue Is Empty"<<endl;
   else{
      cout<<"\nDequeued Data : "<<A[rear--]<<endl;
   }
}

void DeQueue::display()
{
   if (front == rear)
   {
      cout<<"\nEmpty Queue"<<endl;
   }
   else{
      int p= front+1;
      cout<<"\nFront ->  ";
      while(p!=rear)
      {
         cout<<A[p]<<"  ";
         p++;
      }
      cout<<A[p]<<"  <- Rear"<<endl;
   }
}

int main()
{
   int ch{0};
   cout<<"Enter The Size Of The Queue : ";
   int n;cin>>n;

   DeQueue q(n);
   do{
      cout<<"\nMenu :- \n1)ENQUEUE FRONT \n2)ENQUEUE REAR \n3)DEQUEUE FRONT \n4)DEQUEUE REAR \n5)DISPLAY \n6)EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1:
        {
           q.insertFront();
           break;
        }
        case 2:
        {
           q.insertRear();
           break;
        }
        case 3:
        {
           q.deleteFront();
           break;
        }
        case 4:{
           q.deleteRear();
           break;
        }
        case 5:
        {
           cout<<"\nDouble Ended Queue : "<<endl;
           q.display();
           break;
        }
      }
   }while (ch<6);

   return 0;
}

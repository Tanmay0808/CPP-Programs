#include<iostream>
using namespace std;

class ElemPriority
{
   private:
      int front;
      int rear;
      int size;
      int *A;
   public:
      ElemPriority(int n)
      {
         front = rear = -1;
         size = n;
         A = new int[size];
      }
      ~ElemPriority(){delete []A;}
      void enqueue();
      void dequeue();
      void display();
      bool isEmpty(){return (rear == front) ? true : false;}
      bool isFull(){return (rear == size-1) ? true : false;}
};

void ElemPriority::enqueue()
{
   if (isFull())
      cout<<"\nQueue Is Full"<<endl;
   else{
      cout<<"\nEnter Data To Enqueue : ";
      int data;cin>>data;
      if (rear == -1)
      {
         A[++rear] = data;
      }
      else{
         int i=rear;
         while(A[i] < data  && i!=front)
         {
            A[i+1] = A[i];
            i--;
         }
         A[i+1] = data;
         rear++;
      }
   }
}

void ElemPriority::dequeue()
{
   if(isEmpty()){
      front = rear = -1;
      cout<<"\nQueue Is Empty"<<endl;
   }
   else{
      cout<<"\nHighest Priority Data : "<<A[rear--]<<endl;
   }
}

void ElemPriority::display()
{
   if(isEmpty())
      cout<<"\nQueue Is Empty"<<endl;
   else{
      int p=front+1;
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
   cout<<"Enter The Size Of The Queue : ";
   int n;cin>>n;
   ElemPriority P(n);

   int ch{0};
   do{
      cout<<"\nMenu :- \n1)ENQUEUE \n2)DEQUEUE \n3)DISPLAY \n4)EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1:
        {
           P.enqueue();
           break;
        }
        case 2:
        {
           P.dequeue();
           break;
        }
        case 3:
        {
           P.display();
           break;
        }
      }
   }while (ch<4);

   return 0;
}

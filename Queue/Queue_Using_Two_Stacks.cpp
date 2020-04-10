#include<iostream>
using namespace std;

class Stack{
   private:
      int top;
      int *A;
      int size;
   public:
      Stack(int n)
      {
         top=-1;
         A = new int[n];
         size = n;
      }
      ~Stack(){delete []A;}
      void push(int data);
      int pop();
      bool isEmpty(){return (top==-1) ? true : false;}
      bool isFull(){return (top == size-1) ? true : false;}
};

void Stack::push(int data)
{
   A[++top] = data;
}

int Stack::pop()
{
   return A[top--];
}

int main()
{
   cout<<"Enter The Size Of The Queue : ";
   int n;cin>>n;
   Stack s1(n);
   Stack s2(n);

   int ch{0};
   do{
      cout<<"\nMenu :- \n1)ENQUEUE \n2)DEQUEUE \n3)DISPLAY \n4)EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1:
        {
           if(s1.isFull())
              cout<<"\nQueue Is Full"<<endl;
           else{
              cout<<"\nEnter Data To Enqueue : ";
              int data;cin>>data;
              s1.push(data);
           }
           break;
        }
        case 2:
        {
           if(s2.isEmpty())
           {
              if(s1.isEmpty())
                 cout<<"\nQueue Is Empty"<<endl;
              else{
                 while(!s1.isEmpty()){s2.push(s1.pop());}
                 cout<<"\nDequeued Data : "<<s2.pop()<<endl;
              }
           }
           else{
              cout<<"\nDequeued Data : "<<s2.pop()<<endl;
           }
           break;
        }
        case 3:
        {
           cout<<"\nQueue Using 2 Stacks : "<<endl;
           if (s2.isEmpty())
           {
              if(s1.isEmpty())
                 cout<<"\nQueue Is Empty"<<endl;
              else{
                 while(!s1.isEmpty()){
                    s2.push(s1.pop());
                 }
              }
           }
           while(!s2.isEmpty())
           {
              int x = s2.pop();
              cout<<x<<"  ";
              s1.push(x);
           }
           cout<<endl;
           break;
        }
      }
   }while (ch<4);

   return 0;
}

#include<iostream>
using namespace std;

class Stack{
   private:
      int size;
      int top;
      int *A;
   public:
      Stack(int n){
         size = n;
         top = -1;
         A = new int[size];
      }
      ~Stack(){delete []A;}
      void push();
      int pop();
      void peek();
      void stackTop();
      bool isFull();
      bool isEmpty();
      void display();
};

void Stack::push()
{
   cout<<"\nEnter Data To Push : ";
   int data;cin>>data;
   if (top < size - 1)
      A[++top] = data;
   else
      A[size-1] = data;
}

int Stack::pop()
{
  return A[top--];
}

void Stack::peek(){
   cout<<"\nEnter Pos To Retrieve Data : ";
   int pos;cin>>pos;
   if (!isEmpty() && top-pos+1>0){
      cout<<"\nData At Position "<<pos<<"  :  "<<A[top-pos+1]<<endl;
   }
   else{
      cout<<"\nInvalid Attempt"<<endl;
   }
}

void Stack::stackTop()
{
   if (!isEmpty())
      cout<<"\nTop : "<<top<<"\nTop Of Stack Contains Data : "<<A[top]<<endl;
   else
      cout<<"\nTop : "<<top<<"\nStack Is Empty"<<endl;
}

bool Stack::isEmpty()
{
   return (top==-1) ? true : false;
}

bool Stack::isFull()
{
   return (top==size-1) ? true : false;
}

void Stack::display()
{
   cout<<"\nStack : -\n"<<endl;
   for (int i=top;i>=0;i--)
   {
      cout<<"|   "<<A[i]<<"   |"<<endl;
   }
}

int main(){
   cout<<"Enter The Size Of The Stack : ";
   int n;cin>>n;
   Stack s(n);
   int ch{0};
   do{
      cout<<"\nMenu : \n1) PUSH \n2) POP \n3) PEEK \n4) STACKTOP \n5) DISPLAY \n6) EXIT \nEnter Choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            if (!s.isFull())
               s.push();
            else
               cout<<"\nSTACK FULL"<<endl;
            break;
         }
         case 2:
         {
            if (!s.isEmpty())
               cout<<"\nPopped Data : "<<s.pop()<<endl;
            else
               cout<<"\nSTACK EMPTY"<<endl;
            break;
         }
         case 3:
         {
            s.peek();
            break;
         }
         case 4:
         {
            s.stackTop();
            break;
         }
         case 5:
         {
            s.display();
            break;
         }
      }
   }while(ch<6);

   return 0;
}

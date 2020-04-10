#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node *next;
};

class Stack{
   private:
      Node *head;
      int size;
      int top;
   public:
   Stack(int n)
   {
      head = NULL;
      size = n;
      top = -1;
   }
   ~Stack()
   {
      while(head)
      {
         Node *tmp = head;
         head = head->next;
         delete tmp;
      }
   }
   void push();
   void pop();
   void stackTop();
   void peek();
   bool isEmpty(){return (head==NULL) ? true : false;}
   bool isFull(){return (top==size-1) ? true : false;}
   void display();
};

void Stack::display()
{
   Node *p = head;
   cout<<"\nStack : -\n"<<endl;
   while(p!=NULL)
   {
      cout<<"|   "<<p->data<<"   |"<<endl;
      p = p->next;
   }
}

void Stack::push()
{
   if(!isFull()){
      cout<<"\nEnter Data To Push : ";
      int data;cin>>data;
      if (head == NULL)
      {
         head = new Node;
         head->data = data;
         head->next = NULL;
         top++;
      }
      else{
         Node *tmp = new Node;
         tmp->data = data;
         tmp->next = head;
         head = tmp;
         top++;
      }
   }
   else{
      cout<<"\nSTACK FULL"<<endl;
   }
}

void Stack::pop()
{
   if (!isEmpty()){
      if (head == NULL)
         cout<<"\nStack Empty"<<endl;
      else{
         Node *tmp = head;
         cout<<"\nPopped Data : "<<head->data<<endl;
         head = head->next;
         delete tmp;
         top--;
      }
   }
   else{
      cout<<"\nSTACK EMPTY"<<endl;
   }
}

void Stack::stackTop()
{
   if (!isEmpty())
      cout<<"\nTop : "<<top<<"\nTop Contains Data : "<<head->data<<endl;
   else
      cout<<"\nTop : -1\nStack Is Empty"<<endl;
}

void Stack::peek()
{
   cout<<"\nEnter Index To Obtain Data : ";
   int ind;cin>>ind;
   Node *p = head;
   if (ind >= 0 && ind<=top && !isEmpty()){
      for (int i=0;i<top-ind;i++)
      {
         p = p->next;
      }
      cout<<"\nData At Index "<<ind<<"  :  "<<p->data<<endl;
   }
   else{
      cout<<"\nInvalid Attempt"<<endl;
   }
}

int main()
{
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
            s.push();
            break;
         }
         case 2:
         {
            s.pop();
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

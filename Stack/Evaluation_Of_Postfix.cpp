#include<iostream>
using namespace std;

class Stack{
   private:
      int top;
      int size;
      int *A;
   public:
      Stack(int n)
      {
         top=-1;
         size=n;
         A= new int[n];
      }
      ~Stack(){delete []A;}
      void push(int val);
      int pop();
      bool isEmpty(){return (top==-1) ? true : false;}
      bool isFull(){return (top==size-1) ? true : false;}
};

void Stack::push(int val)
{
   A[++top] = val;
}

int Stack::pop()
{
   if(!isEmpty())
      return A[top--];
   return -1;
}

bool isOperand(char ch)
{
   if (ch=='+' || ch=='*' || ch=='-' || ch=='/')
      return false;
   return true;
}

int evalPostfix(string exp)
{
   Stack s(exp.size());
   int x1,x2,res;
   for (int i=0;exp[i]!='\0';i++)
   {
      if (isOperand(exp[i]))
         s.push(exp[i] - '0');
      else{
         x2 = s.pop();
         x1 = s.pop();
         switch(exp[i])
         {
            case '+':
            {
               res = x1 + x2;
               break;
            }
            case '-':
            {
               res = x1 - x2;
               break;
            }
            case '*':
            {
               res = x1 * x2;
               break;
            }
            case '/':
            {
               res = x1 / x2;
               break;
            }
         }
         s.push(res);
      }
   }
   return res;
}

int main()
{
   cout<<"Enter Postfix Expression To Evaluate : ";
   string st;
   cin>>st;

   int res = evalPostfix(st);
   cout<<"\nResult  =  "<<res<<endl;

   return 0;
}

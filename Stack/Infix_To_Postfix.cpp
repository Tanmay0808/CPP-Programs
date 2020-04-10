#include<iostream>
#include<string.h>
using namespace std;

class Stack{
   private:
      int top;
      int size;
      char *A;
   public:
      Stack(int n)
      {
         top=-1;
         size=n;
         A = new char[n];
      }
      ~Stack(){delete []A;}
      void push(char ch);
      char pop();
      char stackTop();
      bool isEmpty(){return (top==-1) ? true : false;}
      bool isFull(){return (top==size-1) ? true : false;}
};

void Stack::push(char ch)
{
   A[++top] = ch;
}

char Stack::pop()
{
   if (!isEmpty())
      return A[top--];
   else
      return '\0';
}

char Stack::stackTop()
{
   if (!isEmpty())
      return A[top];
   else
      return '\0';
}

bool isOperand(char ch)
{
   if (ch=='+' || ch=='*' || ch=='-' || ch=='/')
      return false;
   return true;
}

int precedence(char ch)
{
   if (ch=='+' || ch=='-')
      return 1;
   else if (ch=='*' || ch=='/')
      return 2;
   return 0;
}

string infixtoPostfix(string exp)
{
   Stack s(exp.size());
   string postfix = "";
   int i=0,j=0;
   while (exp[i]!='\0')
   {
      if (isOperand(exp[i]))
      {
         postfix += exp[i++];
      }
      else{
         if (precedence(exp[i]) > precedence(s.stackTop()))
            s.push(exp[i++]);
         else
            postfix += s.pop();
      }
   }
   while(!s.isEmpty())
   {
      postfix += s.pop();
   }
   return postfix;
}

int main()
{
   cout<<"Infix Expression : ";
   string st;cin>>st;

   string res = infixtoPostfix(st);
   cout<<"\nPostfix Expression : \n"<<endl<<res<<endl;

   return 0;
}

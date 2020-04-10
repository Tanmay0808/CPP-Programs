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
         A = new int[n];
      }
      ~Stack(){delete []A;}
      void push(char ch);
      char pop();
      char stackTop();
      bool isEmpty(){return (top==-1) ? true : false;}
      bool isFULL(){return (top==size-1) ? true : false;}
};

void Stack::push(char ch)
{
    A[++top] = ch;
}

char Stack::pop()
{
   if (!isEmpty())
      return A[top--];
   return '\0';
}

char Stack::stackTop()
{
   if (!isEmpty())
      return A[top];
   return '\0';
}

bool isOperand(char ch)
{
   if (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>=48 && ch<=57)
      return true;
   return false;
}

int out_prec(char ch)
{
   if (ch=='+' || ch=='-')
      return 1;
   else if (ch=='*' || ch=='/')
      return 3;
   else if (ch=='^')
      return 6;
   else if (ch=='(')
      return 7;
   else if(ch==')')
      return 0;
   return -1;
}

int in_prec(char ch)
{
   if (ch=='+' || ch=='-')
      return 2;
   else if (ch=='*' || ch=='/')
      return 4;
   else if (ch=='^')
      return 5;
   else if (ch=='(')
      return 0;
   return -1;
}

string infixPostfix(string exp)
{
   Stack s(exp.size());
   string postfix = "";
   int i=0;
   while (exp[i]!='\0')
   {
     if (isOperand(exp[i]))
        postfix += exp[i++];
     else{
        if (out_prec(exp[i]) > in_prec(s.stackTop()))
           s.push(exp[i++]);
        else if (out_prec(exp[i]) == in_prec(s.stackTop())){
           char k = s.pop();
           i++;
        }
        else
           postfix += s.pop();
     }
   }
   while (!s.isEmpty())
   {
      postfix += s.pop();
   }
   return postfix;
}

int main(){
   cout<<"Infix Expression : ";
   string st;
   cin>>st;

   string result = infixPostfix(st);
   cout<<"\nPostfix Expression : \n"<<endl<<result<<endl;

   return 0;
}

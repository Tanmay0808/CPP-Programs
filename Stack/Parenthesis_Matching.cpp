#include<iostream>
#include<math.h>
using namespace std;

class Stack{
   private:
      int top;
      int size;
      char *A;
   public:
      Stack(int n){
         top=-1;
         size = n;
         A = new char[n];
      }
      ~Stack(){delete []A;}
      void push(char &ch);
      char pop();
      bool isEmpty(){return (top==-1) ? true : false;}
      bool isFull(){return (top==size-1) ? true : false;}
};

void Stack::push(char &ch)
{
   A[++top] = ch;
}

char Stack::pop()
{
    return A[top--];
}

bool isBalanced(Stack &s, string &exp)
{
   char x;
   for (int i=0;exp[i]!='\0';i++)
   {
      if (exp[i] == '(' || exp[i]=='{' || exp[i]=='[')
         s.push(exp[i]);
      else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
      {
         if (!s.isEmpty()){
            x = s.pop();
            if (abs(exp[i] - x) > 2)
               return false;
         }
         else{
            return false;
         }
      }
   }
   if (s.isEmpty())
      return true;
   return false;
}

int main()
{
   cout<<"Enter The Expression To Check : ";
   string s;cin>>s;

   Stack stk(s.size());

   if (isBalanced(stk,s))
      cout<<"\nParenthesis Balanced"<<endl;
   else
      cout<<"\nParenthesis Not Balanced"<<endl;

   return 0;
}

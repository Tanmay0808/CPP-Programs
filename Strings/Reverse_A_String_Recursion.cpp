#include<iostream>
using namespace std;

string ReverseStringRecursion(string st,int len)
{
   if (len < 0)
      return "";
   return st[len] + ReverseStringRecursion(st,len-1);
}

int main()
{
   cout<<"Enter The String : ";
   string st;
   cin>>st;

   ///Finding The Length Of String
   int i;
   for (i=0;st[i]!='\0';i++){}
   int len = i-1;

   string result = ReverseStringRecursion(st,len);
   cout<<"\nReversed String : "<<result<<endl;

   return 0;
}

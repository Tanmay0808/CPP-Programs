#include<iostream>
using namespace std;

void ReverseStr(string str, int len)
{
   for (int i=0,j=len;i<j;i++,j--)
      swap(str[i],str[j]);
   cout<<"\nReversed String : "<<str<<endl;
}

int main()
{
   cout<<"Enter The String : ";
   string st;
   cin>>st;

   ///Finding Length Of String
   int i;
   for (i=0;st[i]!='\0';i++){}
   int len = i-1;

   ReverseStr(st,len);

   return 0;
}

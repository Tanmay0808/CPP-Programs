#include<iostream>
using namespace std;

bool Palindrome(string str,int len)
{
   for (int i=0,j=len;i<j;i++,j--)
   {
      if (str[i] != str[j])
         return false;
   }
   return true;
}

int main()
{
   cout<<"Enter The String To Check For Palindrome : ";
   string str;
   cin>>str;

   ///Finding The Length
   int i;
   for (i=0;str[i]!='\0';i++){}
   int len = i-1;

   if(Palindrome(str,len))
      cout<<"\nString Is A Palindrome"<<endl;
   else
      cout<<"\nString Is Not A Palindrome"<<endl;

   return 0;
}

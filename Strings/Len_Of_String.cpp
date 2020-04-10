#include<iostream>
using namespace std;

int LengthStr(char *B)
{
   int i=0;
   while (B[i] != '\0')
      i++;
   return i;
}

int main()
{
   cout<<"Enter The String : ";
   char *str;
   cin>>str;

   int res = LengthStr(str);
   cout<<"\nLength Of String : "<<res<<endl;

   return 0;
}

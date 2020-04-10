#include<iostream>
using namespace std;

void ChangeCase(char *B)
{
   for (int i=0;B[i] != '\0';i++)
   {
      if (B[i] >= 'A' && B[i]<='Z')
         B[i] += 32;
      else if (B[i] >= 'a' && B[i]<='z')
         B[i] -= 32;
   }
   cout<<"\nString After Changing  : "<<B<<endl;
}

int main()
{
   cout<<"Enter The String : ";
   char *st;
   cin>>st;

   ChangeCase(st);

   return 0;
}

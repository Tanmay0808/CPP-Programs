#include<iostream>
using namespace std;

void DuplicatesUsingHashMethod(string s,int len)
{
   int H_S[26]{0},H_C[26]{0};
   for (int i=0;i<=len;i++)
   {
      if (s[i]>='a' && s[i]<='z')
      {
         H_S[s[i] - 97]++;
      }
      if (s[i]>='A' && s[i]<='Z')
      {
         H_C[s[i] - 65]++;
      }
   }

   for (int j=0;j<26;j++)
   {
      if (H_S[j]>1)
         cout<<"\nCharacter ' "<<static_cast<char>(j+97)<<" ' Has "<<" Duplicates : "<<H_S[j]<<endl;
      else if (H_C[j]>1)
         cout<<"\nCharacter ' "<<static_cast<char>(j+65)<<" ' Has "<<" Duplicates : "<<H_C[j]<<endl;
   }
}

int main()
{
   cout<<"Enter The String : ";
   string s;
   cin>>s;

   ///Finding Length
   int i=0;
   for (i=0;s[i]!='\0';i++){}
   int len = i-1;

   DuplicatesUsingHashMethod(s,len);

   return 0;
}

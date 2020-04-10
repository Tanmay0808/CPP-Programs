#include<iostream>
using namespace std;

void ChcekAnagrams(string str1,string str2)
{
   int h[26]{0},i,j;
   for (i=0;str1[i]!='\0';i++){
      h[str1[i] - 97] += 1;
   }
   for (j=0;str2[j]!='\0';j++){
      h[str2[j] - 97] -= 1;
      if (h[str2[j]-97]<0)
      {
         cout<<"\nStrings Are Not Anagrams"<<endl;
         break;
      }
   }
   if (str2[j]=='\0')
      cout<<"\nStrings Are Anagrams"<<endl;
}

int main()
{
   ///String 1
   cout<<"Enter First String : ";
   string st1="";
   cin>>st1;

   ///String 2
   cout<<"\nEnter Second String : ";
   string st2="";
   cin>>st2;

   ChcekAnagrams(st1,st2);

   return 0;
}

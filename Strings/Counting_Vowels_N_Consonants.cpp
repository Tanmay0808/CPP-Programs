#include<iostream>
using namespace std;

void CountVowelConsonant(string B)
{
   int v_cnt = 0,c_cnt = 0;
   for (int i=0;B[i] != '\0';i++)
   {
      if (B[i]=='a'||B[i]=='e'||B[i]=='i'||B[i]=='o'||B[i]=='u'||B[i]=='A'||B[i]=='E'||B[i]=='O'||B[i]=='I'||B[i]=='U')
         v_cnt ++;
      else if ((B[i]>='A' && B[i]<='Z')||(B[i]>='a' && B[i]<='z'))
         c_cnt++;
   }
   cout<<"\nNumber Of Vowels : "<<v_cnt<<endl<<"Number Of Consonants : "<<c_cnt<<endl;
}

int main()
{
   cout<<"Enter The String : ";
   string st;
   getline(cin,st);

   CountVowelConsonant(st);

   return 0;
}

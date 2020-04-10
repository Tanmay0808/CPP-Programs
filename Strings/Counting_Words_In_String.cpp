#include<iostream>
using namespace std;

void CountWordsInString(string B)
{
   int word=1;
   for (int i=0;B[i]!='\0';i++)
   {
      if (B[i]==' ' && B[i-1]!=' ')
         word++;
   }
   cout<<"\nNumber Of Words : "<<word<<endl;
}

int main()
{
   cout<<"Enter The String : ";
   string str;
   getline(cin,str);

   CountWordsInString(str);

   return 0;
}

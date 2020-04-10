#include<iostream>
using namespace std;

bool CheckSubString(string str,string sub)
{
   for (int i=0;str[i]!='\0';i++)
   {
      if (sub[0] == str[i])
      {
         for (int j=1;sub[j]!='\0';j++)
         {
            if (sub[j]!=str[i+j])
               return false;
         }
         return true;
      }
   }
   return false;
}

int main()
{
  cout<<"Enter The String : ";
  string str;
  cin>>str;
  cout<<"\nEnter The Sub-string To Find In Main String : ";
  string sub;
  cin>>sub;

  if (CheckSubString(str,sub))
     cout<<"\nGiven String  \" "<<str<<" \"  Contains  \" "<<sub<<" \" "<<endl;
  else
     cout<<"\nGiven String  \" "<<str<<" \"  Does Not Contains \" "<<sub<<" \" "<<endl;
  return 0;
}

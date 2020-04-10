#include<iostream>
using namespace std;

void PermutationsUsingSwap(string str,int l,int h)
{
   if (l==h){
      for (int i=0;i<=h;i++)
         cout<<str[i];
      cout<<" ";
   }
   else
   {
      for (int i=l;i<=h;i++)
      {
         swap(str[i],str[l]);
         PermutationsUsingSwap(str,l+1,h);
         swap(str[i],str[l]);
      }
   }
}

int main()
{
   cout<<"Enter The String : ";
   string str;
   cin>>str;

   ///Finding The Length
   int i;
   for (i=0;str[i]!='\0';i++){}
   int len = i-1;

   cout<<"\nAll Permutations Of String : - "<<endl;
   PermutationsUsingSwap(str,0,len);

   return 0;
}

#include<iostream>
using namespace std;

void CheckDuplicateUsingBits(string s1)
{
   int h=0,x=0,i=0;
   while (s1[i] != '\0')
   {
      x = 1;
      x = x<<(s1[i] - 97);
      if (x & h > 0){
         cout<<"\nDuplcate Found For ' "<<s1[i]<<" '"<<endl;
      }
      else{
         h = x | h;
      }
      i++;
   }
}

int main()
{
   cout<<"Enter The String : ";
   string strng;
   cin>>strng;

   CheckDuplicateUsingBits(strng);

   return 0;
}

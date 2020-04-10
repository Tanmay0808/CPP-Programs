#include<iostream>
using namespace std;

void Perm(string st,int k)
{
    static int Flag_arr[20];
    static char Res_arr[20];
    if (st[k]=='\0'){
       Res_arr[k]='\0';
       for (int l=0;l<=k;l++)
          cout<<Res_arr[l];
       cout<<" ";
    }
    else{
       for (int i=0;st[i]!='\0';i++)
       {
          if (Flag_arr[i]==0){
             Res_arr[k] = st[i];
             Flag_arr[i] = 1;
             Perm(st,k+1);
             Flag_arr[i]=0;
          }
       }
    }
}

int main()
{
   cout<<"Enter The String : ";
   string str;
   cin>>str;

   cout<<"\nAll Permutations Of Given String : -"<<endl;
   Perm(str,0);

   return 0;
}

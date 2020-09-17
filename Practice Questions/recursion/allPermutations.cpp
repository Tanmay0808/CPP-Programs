#include<iostream>
using namespace std;

void allPermutations(string &s, int l,int r)
{
    if (l == r)
    {
        cout<<s<<endl;
    }
    else{
        for (int i=l;i<=r;i++)
        {
            swap(s[i],s[l]);
            allPermutations(s,l+1,r);
            swap(s[i],s[l]);
        }
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    cout<<"Permutations of "<<s<<" : \n";
    allPermutations(s,0,s.size()-1);
    return 0;
}

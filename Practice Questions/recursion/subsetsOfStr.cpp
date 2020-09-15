#include<iostream>
using namespace std;

void printSubsets(string &str, string curr="", int index=0)
{
    if (index == str.size())
    {
        cout<<curr<<endl;
        return;
    }
    printSubsets(str, curr,index+1);
    printSubsets(str, curr + str[index], index+1);
}

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    cout<<"All Subsets of "<<str<<" : "<<endl;
    printSubsets(str);
    return 0;
}

#include<iostream>
#include<unordered_map>
using namespace std;

int timeToType(string &keyboard,string &word)
{
    unordered_map<char,int> lookup;
    for (int i=0;i<26;i++)
    {
        lookup[keyboard[i]] = i;
    }

    int time = 0, st = 0;

    for (int i=0;word[i]!='\0';i++)
    {
        time += abs(st - lookup[word[i]]);
        st = lookup[word[i]];
    }
    return time;
}

int main(int argc, char const *argv[])
{
    string keyboard, word;
    cin>>keyboard>>word;
    cout<<timeToType(keyboard,word)<<endl;
    return 0;
}

#include<iostream>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    return (s[start] == s[end]) && isPalindrome(s, start + 1, end -1);
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    cout<<( isPalindrome(s,0,s.size() - 1) ? "String is a palindrome" : "String is not a palindrome" )<<endl;
    return 0;
}

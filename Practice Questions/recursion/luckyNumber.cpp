#include<iostream>
using namespace std;

bool isLucky(int n, int counter=2)
{
    if (n%counter == 0) return false;
    if (counter > n) return true;
    return isLucky(n - n/counter, counter+1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    if (isLucky(n))
    {
        cout<<"Number is lucky"<<endl;
    }
    else{
        cout<<"Number is not lucky"<<endl;
    }
    return 0;
}

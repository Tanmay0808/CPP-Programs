#include<iostream>
using namespace std;

void nBonacciNumbers(int n, int m)
{
    int a[m], sum = 1;
    fill(a, a + n - 1, 0);
    a[n-1] = 1;
    for (int i=n ; i<m ; i++)
    {
        a[i] = sum;
        sum += (a[i] - a[i-n]);
    }

    //printing
    for (int i=0;i<m;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin>>n>>m;
    cout<<"First "<<m<<" N-bonacci numbers : "<<endl;
    nBonacciNumbers(n, m);
    return 0;
}

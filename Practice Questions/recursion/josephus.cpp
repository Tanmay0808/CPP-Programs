#include<iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1) return 0;
    return (josephus(n-1,k) + k)%n; 
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    cout<<"Survivour : "<<josephus(n,k)<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int digitalRoot(int n)
{
    int sum = 0;
    if (n < 10) return n;
    sum += (n%10 + digitalRoot(n/10));
    return digitalRoot(sum);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<"Digital Root of "<<n<<" = "<<digitalRoot(n)<<endl;
    return 0;
}

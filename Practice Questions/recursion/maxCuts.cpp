/*
Given a rope of size n, find the maximum no. of pieces that can be made of lengths in set {a,b,c}
*/

#include<iostream>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
    if (n == 0) return 0;
    if (n < 0) return -1;
    int max, x, y, z;
    x = maxCuts(n-a, a, b, c);
    y = maxCuts(n-b, a, b, c);
    z = maxCuts(n-c, a, b, c);
    max = x > y && x > z ? x : y > z ? y : z;
    return max != -1 ? max + 1 : -1;
}

int main(int argc, char const *argv[])
{
    int n, a, b, c;
    cout<<"Enter n, a, b, c : ";
    cin>>n>>a>>b>>c;
    cout<<"Maximum Pieces : "<<maxCuts(n, a, b, c)<<endl;
    return 0;
}

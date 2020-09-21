#include<iostream>
using namespace std;

//Naive
int maxSumSubarray(int a[], int n)
{
    int res = 0;
    for (int i=0;i<n;i++)
    {
        int curr = 0;
        for (int j=i;j<n;j++)
        {
            curr = curr + a[j];
            res = max(res, curr);
        }
    }
    return res;
}

//Efficient
int maxSum(int a[], int n)
{
    int res = a[0], prev_max = a[0];
    for (int i=0;i<n;i++)
    {
        prev_max = max(prev_max + a[i], a[i]);
        res = max(prev_max, res);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Max Subarray Sum : "<<maxSum(a, n)<<endl;
    return 0;
}

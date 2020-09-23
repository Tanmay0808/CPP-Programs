#include<iostream>
using namespace std;

//Naive
int maxSumOfElems(int a[], int n, int k)
{
    int maxSum = INT32_MIN;
    for (int i=0;i + k - 1<n;i++)
    {
        int sum = 0;
        for (int j=0;j<k;j++)
        {
            sum += a[i + j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

//Efficient
int maxSumUsingSlidingWindow(int a[], int n, int k)
{
    int ini_sum = 0;
    for (int i=0;i<k;i++)
    {
        ini_sum += a[i];
    }
    int max_sum = ini_sum;
    for (int i=k;i<n;i++)
    {
        ini_sum += (a[i] - a[i-k]);
        max_sum = max(max_sum, ini_sum);
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Maximum sum : "<<maxSumUsingSlidingWindow(a, n, k)<<endl;
    return 0;
}

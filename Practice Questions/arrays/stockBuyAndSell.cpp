#include<iostream>
using namespace std;

//Naive 
int maxProfit(int a[], int n, int start, int end)
{
    if (end <= start)
    {
        return 0;
    }
    int profit = 0;
    for (int i=start;i<end;i++)
    {
        for (int j=i+1;j<=end;j++)
        {
            if (a[j] > a[i])
            {
                int curr_profit = a[j] - a[i] + maxProfit(a, n, start, i-1) + maxProfit(a, n, j+1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

//Efficient 
int maximumProfit(int a[], int n)
{
    int profit = 0;
    for (int i=1;i<n;i++)
    {
        if (a[i] > a[i-1])
        {
            profit += (a[i] - a[i-1]);
        }
    }
    return profit;
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
    cout<<"Max Profit : "<<maximumProfit(a, n)<<endl;
    return 0;
}

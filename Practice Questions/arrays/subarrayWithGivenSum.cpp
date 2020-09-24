#include<iostream>
using namespace std;

//Naive 
bool isSubarrayWithSum(int a[], int n, int given_sum)
{
    for (int i=0;i<n;i++)
    {
        int sum = 0;
        for (int j=i;j<n;j++)
        {
            sum += a[j];
            if (sum == given_sum)
            {
                return true;
            }
        }
    }
    return false;
}

//Efficient (Sliding window)
bool isSubarrayPresent(int a[], int n, int given_sum)
{
    int curr_sum = a[0], start=0;
    for (int end=1;end<n;end++)
    {
        while (curr_sum > given_sum && start < end - 1){
            curr_sum -= a[start];
            start++;
        }
        if (curr_sum == given_sum)
        {
            return true;
        }
        if (end < n)
        {
            curr_sum += a[end];
        }
    }
    return (curr_sum == given_sum);
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin>>n>>sum;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if (isSubarrayPresent(a, n, sum))
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

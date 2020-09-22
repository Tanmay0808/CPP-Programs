#include<iostream>
using namespace std;

//Naive
int maxSumCircularArray(int a[], int n)
{
    int res = a[0];
    for (int i=0;i<n;i++)
    {
        int curr_sum = a[i];
        int curr_max = a[i];
        for (int j=1;j<n;j++)
        {
            int index = (i+j)%n;
            curr_sum += a[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
}

//Efficient
int maxNormal(int a[], int n)
{
    int res = a[0], max_so_far = a[0];
    for (int i=1;i<n;i++)
    {
        max_so_far = max(max_so_far + a[i], a[i]);
        res = max(max_so_far, res);
    }
    return res;
}

int overallMaxSum(int a[], int n)
{
    int maxNorm = maxNormal(a, n);
    if (maxNorm < 0)
    {
        return maxNorm;
    }
    int arr_sum = 0;
    for (int i=0;i<n;i++)
    {
        arr_sum += a[i];
        a[i] = -a[i];
    }
    int maxCirc = arr_sum + maxNormal(a, n);
    return max(maxNorm, maxCirc); 
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Max circular subarray sum : "<<overallMaxSum(a, n)<<endl;
    return 0;
}

#include<iostream>
using namespace std;

//Naive (Recursive)
int countSubsetWithSumK(int *A, int n, int sum)
{
    if (n==0)
    {
        return sum == 0 ? 1 : 0; 
    }
    return countSubsetWithSumK(A,n-1,sum) + countSubsetWithSumK(A, n-1, sum - A[n-1]);
}

//Another way (without modifying sum)
int countSubsets(int *A, int n, int sum, int curr_sum=0)
{
    if (n==0)
    {
        return curr_sum == sum ? 1 : 0;
    }
    return countSubsets(A, n-1, sum, curr_sum) + countSubsets(A, n-1, sum, curr_sum + A[n-1]);
}

int main(int argc, char const *argv[])
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"No. Of Subsets With Sum "<<sum<<" = "<<countSubsetWithSumK(arr,n,sum)<<endl;
    cout<<"No. Of Subsets With Sum "<<sum<<" = "<<countSubsets(arr,n,sum)<<endl;
    return 0;
}

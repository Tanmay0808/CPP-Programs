#include<bits/stdc++.h>
using namespace std;

int maxSum(int a[], int n)
{
    int res=a[0], curr=a[0];
    for (int i=1;i<n;i++)
    {
        curr = max(curr+a[i], a[i]);
        res = max(res, curr);
    }
    return res;
}

int circularSubarraySum(int a[], int n){
   
    int linear_max = maxSum(a, n);
    if (linear_max < 0)
    {
        return linear_max;
    }
   
    int arr_sum=0;
    for (int i=0;i<n;i++)
    {
        arr_sum += a[i];
        a[i] = -a[i];
    }
   
    int circular_max = maxSum(a, n) + arr_sum;
   
    return max(linear_max, circular_max);
}

int main()
 {
int T;

//testcases
cin>> T;

while (T--)
{
   int num;
   
   //size of array
   cin>>num;
   int arr[num];
   
   //inserting elements
   for(int i = 0; i<num; i++)
       cin>>arr[i];
   
   //calling function
   cout << circularSubarraySum(arr, num) << endl;
   
}

return 0;
} 

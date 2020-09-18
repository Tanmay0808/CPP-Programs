/*
  Find maximum arr[j] - arr[i], where j > i
*/

#include<iostream>
using namespace std;

//Naive 
int maxDiff(int a[], int n)
{
    int res = a[1] - a[0];
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            res = max(res, a[j] - a[i]);
        }
    }
    return res;
}

//Efficient
int maxDifference(int a[], int n)
{
    int res = a[1] - a[0], min_so_far = a[0];
    for (int j=1;j<n;j++)
    {
        res = max(res, a[j] - min_so_far);
        min_so_far = min(min_so_far, a[j]);
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
    cout<<"Max difference : "<<maxDifference(a, n)<<endl;
    return 0;
}

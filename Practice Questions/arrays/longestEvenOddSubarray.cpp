#include<iostream>
using namespace std;

//Naive
int maxLength(int a[], int n)
{
    int res = 1;
    for (int i=0;i<n;i++)
    {
        int count = 1;
        for (int j=i+1;j<n;j++)
        {
            if ((a[j]%2==0 && a[j-1]%2!=0) || (a[j]%2!=0 && a[j-1]%2==0))
            {
                count++;
            }
            else{
                break;
            }
        }
        res = max(res, count);
    }
    return res;
}

//Efficient
int maxLen(int a[], int n)
{
    int res=1, count=1;
    for (int i=1;i<n;i++)
    {
        if ((a[i]%2==0 && a[i-1]%2!=0) || (a[i]%2!=0 && a[i-1]%2==0))
        {
            count++;
            res = max(res, count);
        }
        else{
            count = 1;
        }
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
    cout<<"Length of longest even-odd array : "<<maxLen(a, n)<<endl;
    return 0;
}

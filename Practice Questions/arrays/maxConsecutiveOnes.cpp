#include<iostream>
using namespace std;

//Naive
int maxConsecutiveOnes(int a[], int n)
{
    int res = 0;
    for (int i=0;i<n;i++)
    {
        int count = 0;
        for (int j=i;j<n;j++)
        {
            if (a[j] == 0)
            {
                break;
            }
            else{
                count = count + 1;
            }
        }
        res = max(res, count);
    }
    return res;
}

//Efficient
int maxOnes(int a[], int n)
{
    int res = 0, cnt = 0;
    for (int i=0;i<n;i++)
    {
        if (a[i] == 0)
            cnt = 0;
        else{
            cnt++;
            res = max(res,cnt);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n ;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Max Consecutive 1's : "<<maxOnes(a, n)<<endl;
    return 0;
}

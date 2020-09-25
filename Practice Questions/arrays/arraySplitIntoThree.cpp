/*
  Given an array, return true if it can be divided into 3 subarrays with equal sum, else return false.
*/

#include<iostream>
using namespace std;

//Naive
bool isPossible(int a[], int n)
{
    if (n < 3){return false;}
    if (n == 3){return (a[0]==a[1] && a[0] == a[2]) ? true : false;}

    int prefix[n], suffix[n], array_sum=a[0];
    prefix[0] = a[0], suffix[n-1] = a[n-1];
    
    for (int i=1;i<n;i++)
    {
        array_sum += a[i];
        prefix[i] = prefix[i-1] + a[i];
        suffix[n - i - 1] = suffix[n - i] + a[n - i - 1];
    }

    int start = 0, end = n-1;
    while (start < end)
    {
        if (prefix[start] == suffix[end])
        {
            if ( (array_sum - prefix[start] - suffix[end]) == prefix[start] )
            {
                return true;
            }
            start++;
            end--;
        }
        else if (prefix[start] < suffix[end])
        {
            start++;
        }
        else{
            end--;
        }
    }
    return false;
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
    if (isPossible(a,n))
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

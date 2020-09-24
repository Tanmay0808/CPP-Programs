#include<iostream>
using namespace std;

//Naive
int equiPoint(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        int lsum = 0;
        for (int j=0;j<i;j++){lsum += a[j];}
        int rsum = 0;
        for (int k=i+1;k<n;k++){rsum += a[k];}
        if (lsum == rsum)
        {
            return a[i];
        }
    }
    return -1;
}

//Efficient
int equilibriumPoint(int a[], int n)
{
    int sum = 0;
    for (int i=0;i<n;i++){sum += a[i];}

    if (sum - a[0] == 0)
    {
        return a[0];
    }
    else if(sum - a[n-1] == 0)
    {
        return a[n-1];
    }
    else{
        int curr_sum = 0;
        for (int i=1;i<n-1;i++)
        {
            curr_sum += a[i - 1];
            sum -= a[i-1];
            if (curr_sum == sum - a[i])
            {
                return a[i];
            } 
        }
        return -1;
    }
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
    cout<<"Equilibrium point : "<<equilibriumPoint(a, n)<<endl;
    return 0;
}

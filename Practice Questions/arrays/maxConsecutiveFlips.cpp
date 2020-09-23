#include<iostream>
using namespace std;

//Naive 
void printGroups(int a[], int n)
{
    int zero_count = 0, ones_count=0,prev = a[0];
    if(prev){ones_count++;}
    else{zero_count++;}

    for (int i=1;i<n;i++)
    {
        if (a[i] == 0 && prev == 1)
        {
            zero_count++;prev=0;
        }
        else if (a[i] == 1 && prev == 0)
        {
            ones_count++;prev=1;
        }
    }

    int min_val = ones_count >= zero_count ? 0 : 1;

    for (int i=1;i<n;i++)
    {
        if (a[i] != a[i-1])
        {
            if (a[i] == min_val)
            {
                cout<<"From "<<i<<" To"<<" ";
            }
            else{
                cout<<(i-1)<<endl;
            }
        }
    }
    if (a[n-1] == min_val)
        cout<<(n-1)<<endl;
}

//Efficient
void printFlipGroups(int a[], int n)
{
    for (int i=1;i<n;i++)
    {
        if (a[i] != a[i-1])
        {
            if (a[i] != a[0])
            {
                cout<<"From "<<i<<" To ";
            }
            else{
                cout<<(i-1)<<endl;
            }
        }
    }
    if (a[n-1] != a[0])
    {
        cout<<(n-1)<<endl;
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
    cout<<"Flips required  : \n";
    printFlipGroups(a, n);
    return 0;
}

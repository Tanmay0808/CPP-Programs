#include<iostream>
using namespace std;

//Naive
void printLeaders(int a[], int n)
{
    int flg;
    for(int i=0;i<n;i++)
    {
        flg = 0;
        for (int j=i+1;j<n;j++)
        {
            if (a[j] >= a[i])
            {
                flg = true;
                break;
            }
        }

        if (!flg) {cout<<a[i]<<" ";}
    }
}

//Efficient
void printLeadersInArray(int a[], int n)
{
    int max = a[n-1];
    cout<<max<<" ";
    for (int i=n-2;i>-1;i--)
    {
        if (a[i] > max)
        {
            cout<<a[i]<<" ";
            max = a[i];
        }
    }
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

    cout<<"Leaders in array : \n";
    printLeadersInArray(a, n);

    return 0;
}

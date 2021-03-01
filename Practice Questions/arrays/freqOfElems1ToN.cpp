#include<iostream>
using namespace std;

void countFrequency(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        a[i] = a[i]-1;
    }

    for (int i=0;i<n;i++)
    {
        a[a[i]%n] = a[a[i]%n] + n;
    }

    for (int i=0;i<n;i++)
    {
        cout<<a[i]/n<<" ";
    }
    cout<<endl;
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
    cout<<"Freq. of elements from 1 to "<<n<<" : "<<endl;
    countFrequency(a, n);
    return 0;
}

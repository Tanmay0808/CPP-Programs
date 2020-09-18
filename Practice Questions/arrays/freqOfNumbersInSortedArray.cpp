#include<iostream>
using namespace std;

//Naive
void printFrequencies(int a[], int n)
{
    int freq = 1;
    for (int i=1;i<n;i++)
    {
        if (a[i] == a[i-1])
        {
            freq++;
        }
        else{
            cout<<a[i-1]<<" "<<freq<<endl;
            freq = 1;
        }
    }
    cout<<a[n-1]<<" "<<freq<<endl;
}

//Better way to write
void printFreq(int a[], int n)
{
    int freq = 1, i=1;
    while (i < n)
    {
        while (i<n && a[i-1] == a[i])
        {
            freq++;
            i++;
        }
        cout<<a[i-1]<<" "<<freq<<endl;
        freq=1;i++;
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
    cout<<"Frequencies : "<<endl;
    printFreq(a, n);
    
    return 0;
}

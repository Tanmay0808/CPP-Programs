#include<iostream>
using namespace std;

//Naive
int majorityElement(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        int count = 1;
        for (int j=i+1;j<n;j++)
        {
            if (a[j] == a[i]){count++;}
        }
        if (count > n/2)
            return i;
    }
    return -1;
}

//Efficient 
int majorityElem(int a[], int n)
{
    int res=0, count=1;
    
    //find candidate
    for (int i=1;i<n;i++)
    {
        if (a[res] == a[i])
        {
            count++;
        }
        else{
            count--;
        }
        if (count == 0){res = i, count = 1;}
    }

    //check for majority
    count = 0;
    for (int i=0;i<n;i++)
    {
        if (a[i] == a[res])
        {
            count++;
        }
    }
    if (count <= n/2)
        res = -1;
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
    int res = majorityElem(a, n);
    if ( res != -1)
    {
        cout<<"Majority element : "<<a[res]<<endl;
    }else{
        cout<<"No majority element"<<endl;
    }
    return 0;
}


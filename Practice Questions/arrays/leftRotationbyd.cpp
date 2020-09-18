#include<iostream>
using namespace std;

//Naive
void leftRotateArray(int a[], int n, int d)
{
    int temp[d];
    for (int i=0;i<d;i++)
    {
        temp[i] = a[i];
    }

    for (int i=d;i<n;i++)
    {
        a[i - d] = a[i];
    }

    for (int i=0;i<d;i++)
    {
        a[n - d + i] = temp[i];
    }
}


//Efficient Solution
void reverse(int a[], int start, int end)
{
    while (start < end)
    {
        swap(a[start],a[end]);
        start++;
        end--;
    }
}

void leftRotate(int a[], int n, int d)
{
    reverse(a, 0, d-1);
    reverse(a, d, n-1);
    reverse(a, 0, n-1);
}

int main(int argc, char const *argv[])
{
    int n,d;
    cin>>n>>d;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"Array after left rotation by "<<d<<" digits : \n";
    leftRotateArray(a, n, d);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

#include<iostream>
using namespace std;

//Naive 
int maxOccuringElem(int L[], int R[], int n)
{
    int temp[1000] = {0};
    for (int i=0;i<n;i++)
    {
        for (int j=L[i];j<=R[i];j++)
        {
            temp[j]++;
        }
    }

    int maxV = INT32_MIN, res=-1;
    for (int i=0;i<1000;i++)
    {
        if (maxV < temp[i]){
            maxV = temp[i];
            res = i;
        }
    }
    return res;
}

//Efficient
int maxOccuringElement(int L[], int R[], int n)
{
    int temp_arr[1000] = {0};
    for (int i=0;i<n;i++)
    {
        temp_arr[L[i]]++;
        temp_arr[R[i] + 1]--;
    }

    int maxElem = temp_arr[0], index = 0;
    for (int i=1;i<1000;i++)
    {
        temp_arr[i] += temp_arr[i-1];
        if (temp_arr[i] > maxElem)
        {
            maxElem = temp_arr[i];
            index = i;
        }
    }
    return index;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int L[n], R[n];
    for (int i=0;i<n;i++)
    {
        cin>>L[i]>>R[i];
    }
    cout<<"Max Occuring element in given ranges : "<<maxOccuringElement(L, R, n)<<endl;
    return 0;
}

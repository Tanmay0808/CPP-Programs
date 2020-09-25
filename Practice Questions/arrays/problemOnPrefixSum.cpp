/*
  Given an array of size N with all initial values as 0. Perform given 'm' add operations from index 'a' to 'b' and evaluate highest element in array. An add operation adds 100 to all elements from index a to b (both inclusive).
*/

#include<iostream>
using namespace std;

int maxValue(int L[], int R[], int m)
{
    int prefixSum[1000] = {0};
    for (int i=0;i<m;i++)
    {
        prefixSum[L[i]]++;
        prefixSum[R[i] + 1]--;
    }

    int maxVal=prefixSum[0];
    for (int i=1;i<1000;i++)
    {
        prefixSum[i] += prefixSum[i-1];
        maxVal = max(prefixSum[i], maxVal);
    }
    return maxVal*100;
}

int main(int argc, char const *argv[])
{
    int m;
    cin>>m;
    int L[m], R[m];
    for (int i=0;i<m;i++)
    {
        cin>>L[i]>>R[i];
    }
    cout<<"Max Value : "<<maxValue(L, R, m)<<endl;
    return 0;
}

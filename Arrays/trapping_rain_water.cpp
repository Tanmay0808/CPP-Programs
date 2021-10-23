#include<bits/stdc++.h>

using namespace std;

int trappingWater(int a[], int n){

    int lmax[n], rmax[n];
    lmax[0] = a[0], rmax[n-1] = a[n-1];
    for (int i=1;i<n;i++)
    {
        lmax[i] = max(lmax[i-1], a[i]);
        rmax[n - i - 1] = max(rmax[n-i], a[n - i - 1]);
    }
   
    int water=0;
    for (int i=1;i<n-1;i++)
    {
        water += (min(lmax[i],rmax[i]) - a[i]);
    }
    return water;
}

int main(){
   
    int t;
    //testcases
    cin >> t;
   
    while(t--){
        int n;
       
        //size of array
        cin >> n;
       
        int a[n];
       
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
       
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
       
    }
   
    return 0;
}

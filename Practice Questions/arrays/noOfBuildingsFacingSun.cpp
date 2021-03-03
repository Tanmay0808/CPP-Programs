/*
    Given an array representing heights of buildings. The array has buildings from left to right as shown in below diagram, count number of buildings facing the sunset. It is assumed that heights of all buildings are distinct.
*/

#include<iostream>
using namespace std;

int buildingsFacingSun(int buildings[], int totalCount)
{
    int count_facing_sun=0, curr_max_height=INT32_MIN;
    for (int i=0;i<totalCount;i++)
    {
        if (buildings[i] > curr_max_height)
        {
            curr_max_height = buildings[i];
            count_facing_sun++;
        }
    }
    return count_facing_sun;
}

int main(int argc, char const *argv[])
{
    int n;cin>>n;
    int buildings[n];
    for (int i=0;i<n;i++)
    {
        cin>>buildings[i];
    }
    cout<<"No. of Buildings Facing Sun : "<<buildingsFacingSun(buildings, n)<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

void shortestPath(vector<vector<int>> &grid, int V, int s)
{
    int dist[V];
    fill(dist, dist+V, INT32_MAX);
    dist[s] = 0;

    for (int count=0;count<V-1;count++)
    {
        for (int i=0;i<V;i++)
        {
            for (int j=0;j<V;j++)
            {
                if (grid[i][j]!=0 && dist[i]!=INT32_MAX && dist[j] > dist[i] + grid[i][j])
                    dist[j] = dist[i] + grid[i][j];
            }
        }
    }

    for (int d:dist)
        cout<<d<<" ";

    //Detect negative weight cycle
    for(int i=0;i<V;i++)
    {
        for (int j=0;j<V;j++)
        {
            if (grid[i][j]!=0 && dist[j] > dist[i] + grid[i][j])
            {
                cout<<"Negative weight cycle found"<<endl;
                return;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int V = 4;
    vector<vector<int>> grid = {{0,1,8,0},
                                {0,0,-8,3},
                                {0,0,0,2},
                                {0,0,0,0}};
    cout<<"Shortest Path : ";
    shortestPath(grid, V, 0); 
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

void shortestPath(vector<vector<int>> &grid, int V, int s)
{
    int dist[V];
    fill(dist, dist + V, INT32_MAX);
    bool fin[V];
    fill(fin, fin + V, false);
    dist[s] = 0;

    for (int count=0;count<V;count++)
    {
        int u = -1;
        for (int i=0;i<V;i++)
        {
            if (!fin[i] && (u==-1 || dist[i] < dist[u]))
                u = i;
        }
        fin[u] = true;
        for (int v=0;v<V;v++)
        {
            if (!fin[v] && grid[u][v]!=0)
                dist[v] = min(dist[v], dist[u] + grid[u][v]);
        }
    }

    cout<<"Shortest path from "<<s<<" : ";
    for (int d:dist)
    {
        cout<<d<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int V = 4;
    vector<vector<int>> grid = {{0,5,10,0},
                                {5,0,3,20},
                                {10,3,0,2},
                                {0,20,2,0}};

    shortestPath(grid, V, 0);
    return 0;
}

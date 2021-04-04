/*
    Given an undirected graph and a source vectex, find shortest distance of each vertex from source
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printShortestDistance(vector<int> adj[], int V, int st)
{
    bool visited[V];
    fill(visited, visited + V, false);
    
    queue<int> q;
    q.push(st);
    visited[st] = true;

    int dist[V];
    fill(dist, dist + V, INT32_MAX);
    dist[st] = 0;

    while(!q.empty())
    {
        int u = q.front();q.pop();
        for (int v:adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
    }

    for (int d:dist)
        cout<<d<<" ";
}

int main(int argc, char const *argv[])
{
    int V = 4;
    vector<int> adj[V];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 1);

    printShortestDistance(adj, V, 0);
    cout<<endl;

    return 0;
}

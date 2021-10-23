#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

//Method 1 : Starting vertex is given
void DFS(vector<int> adj[], bool visited[], int st)
{
    visited[st] = true;
    cout<<st<<" ";
    for (int v:adj[st])
        if (!visited[v])
            DFS(adj, visited, v);
}

//Method 2: Starting vertex is not given, graph may be disconnected also
void DFSDis(vector<int> adj[], bool visited[], int V)
{
    for (int i=0;i<V;i++)
        if (!visited[i])
            DFS(adj, visited, i);
}

int main(int argc, char const *argv[])
{
    int V = 4;
    bool visited[V];
    fill(visited, visited + V, false);
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 1);
    DFSDis(adj, visited, V);
    return 0;
}

#include<iostream>
#include<vector>
#define NIL -1
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bridgesUtil(int u, vector<int> adj[], bool visited[], int parent[], int low[], int disc[])
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            bridgesUtil(v, adj, visited, parent, low, disc);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                cout<<u<<" - "<<v<<endl;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void bridges(vector<int> adj[], int V)
{
    bool visited[V];
    int parent[V], low[V], disc[V];
    for (int i=0;i<V;i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    for (int i=0;i<V;i++)
        if (!visited[i])
            bridgesUtil(i, adj, visited, parent, low, disc);
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    cout<<"Bridges : "<<endl;
    bridges(adj, V);    
    return 0;
}

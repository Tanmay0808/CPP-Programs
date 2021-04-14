#include<iostream>
#include<vector>
#define NIL -1
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void APUtil(int u, vector<int> adj[], bool visited[], int parent[], int low[], int disc[], bool ap[])
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u])
    {
        if (!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v, adj, visited, parent, low, disc, ap);

            low[u] = min(low[u], low[v]);
            if ((parent[u]==NIL && children > 1) || (parent[u]!=NIL && low[v] >= disc[u]))
                ap[u] = true;
        }
        else if (v != parent[u])//Back edge
            low[u] = min(low[u], disc[v]);
    }
}

void AP(vector<int> adj[], int V)
{
    bool visited[V], ap[V];
    int low[V], disc[V], parent[V];
    for (int i=0;i<V;i++)
    {
        visited[i] = ap[i] = false;
        parent[i] = NIL;
    }

    for (int i=0;i<V;i++)
        if (!visited[i])
            APUtil(i, adj, visited, parent, low, disc, ap);

    for (int i=0;i<V;i++)
        if (ap[i])
            cout<<i<<" ";
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

    cout<<"Articulation Points : ";
    AP(adj, V);
    cout<<endl;
    return 0;
}

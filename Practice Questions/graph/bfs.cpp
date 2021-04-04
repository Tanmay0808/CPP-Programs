#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Method 1 : When starting vertex is given
void BFS(vector<int> adj[], bool visited[], int st)
{
    queue<int> q;
    visited[st] = true;
    q.push(st);

    while(!q.empty())
    {
        int u = q.front();q.pop();
        cout<<u<<" ";
        for (int v:adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

//Method 2: Starting vertex is not given, graph may be disconnected also
void BFSDis(vector<int>adj[], bool visited[], int V)
{
    for (int i=0;i<V;i++)
    {
        if (!visited[i])
            BFS(adj, visited, i);
    }
}


int main(int argc, char const *argv[])
{
    int V = 7;    
    bool visited[V];
    fill(visited, visited + V, false);

    vector<int> adj[V];
    addEdge(adj, 0,2);
    addEdge(adj, 0,3);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 5,4);
    addEdge(adj, 4,6);
    addEdge(adj, 5,6);
    BFSDis(adj, visited,V);
    return 0;
}

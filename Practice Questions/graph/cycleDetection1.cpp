/*
    Cycle detection in undirected graph
    1) Using DFS
    2) Using BFS
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Using DFS
bool DFSRec(vector<int>adj[], bool visited[], int curr, int parent)
{
    visited[curr] = true;
    for (int v:adj[curr])
    {
        if (!visited[v]){
            if (DFSRec(adj, visited, v, curr) == true)
                return true;
        }
        else if (v != parent)
            return true;
    }
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V];
    fill(visited, visited + V, false);

    for (int i=0;i<V;i++){
        if (!visited[i]){
            if (DFSRec(adj, visited, i, -1) == true){
                return true;
            }
        }
    }
    return false;
}

//Using BFS
bool BFSIte(vector<int> adj[], bool visited[], int V, int s)
{
    int parent[V];
    fill(parent, parent + V, -1);

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();q.pop();
        for (int v : adj[u])
        {
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
            else if (parent[u] != v)
            {
                return true;
            }
        }
    }
    return false;
}

bool BFS(vector<int> adj[], int V)
{
    bool visited[V];
    fill(visited, visited + V, false);
    for (int i=0;i<V;i++)
    {
        if (!visited[i])
        {
            if (BFSIte(adj, visited, V, i) == true)
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int V = 7;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 5);

    cout<<"Using DFS : "<<(DFS(adj, V) ? "Cycle Found" : "No Cycle Found")<<endl;
    cout<<"Using BFS : "<<(BFS(adj, V) ? "Cycle Found" : "No Cycle Found")<<endl;
    
    return 0;
}

/*
    Topological sort
    1) Using BFS (Kahn's Algo)
    2) Using DFS
*/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void setIndegree(vector<int> adj[], int ind[], int V)
{
    for (int i=0;i<V;i++)
    {
        for (int vertex:adj[i])
        {
            ind[vertex]++;
        }
    }
}

//Using BFS
void topoSort(vector<int> adj[], int V)
{
    int indegree[V];
    fill(indegree, indegree + V, 0);

    queue<int> q;
    setIndegree(adj, indegree, V);

    for (int i=0;i<V;i++)
        if (indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int u = q.front();q.pop();
        cout<<u<<" ";
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
}

//Using DFS
void DFSRec(vector<int> adj[], bool visited[], int st, stack<int> &s)
{
    visited[st] = true;
    for (int v : adj[st])
    {
        if (!visited[v])
            DFSRec(adj, visited, v, s);
    }
    s.push(st);
}

void DFS(vector<int> adj[], int V)
{
    bool visited[V];
    fill(visited, visited+V, false);
    stack<int> s;

    for (int i=0;i<V;i++)
        if (!visited[i])
            DFSRec(adj, visited, i, s);
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vector<int> adj[V];

    //addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    cout<<"Topological Sort Using BFS : ";
    topoSort(adj, V);
    cout<<endl;

    cout<<"Topological Sort Using DFS : ";
    DFS(adj, V);
    cout<<endl;
    
    return 0;
}

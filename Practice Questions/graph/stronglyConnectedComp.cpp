#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void DFSRec(vector<int> adj[], bool visited[], stack<int> &s, int sV, bool isTopoSort)
{
    visited[sV] = true;

    if (!isTopoSort){ cout<<sV<<" ";}

    for (int v : adj[sV])
    {
        if (!visited[v])
            DFSRec(adj, visited, s, v, isTopoSort);
    }

    if (isTopoSort){ s.push(sV);}
}

void DFS(vector<int> adj[], bool visited[], stack<int> &s, int &V)
{
    for (int i=0;i<V;i++)
    {
        if (!visited[i])
            DFSRec(adj, visited, s, i, true);
    }
}

void reverseEdges(vector<int> adj[], vector<int> revEdges[], int &V)
{
    for (int i=0;i<V;i++)
    {
        for (int v : adj[i])
        {
            revEdges[v].push_back(i);
        }
    }
}

void kosaRajuAlgo(vector<int> adj[], int V)
{
    stack<int> s;
    vector<int> revEdges[V];
    
    bool visited[V];
    fill(visited, visited+V, false);

    //Step 1
    DFS(adj, visited, s, V);

    //Step 2
    reverseEdges(adj, revEdges, V);

    //Step 3
    fill(visited, visited+V, false);
    while(!s.empty())
    {
        int u = s.top();s.pop();
        if (!visited[u]){
            DFSRec(revEdges, visited, s, u, false);
            cout<<endl;
        }    
    }
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 4);
    
    cout<<"Strongly connected components : "<<endl;
    kosaRajuAlgo(adj, V);

    return 0;
}

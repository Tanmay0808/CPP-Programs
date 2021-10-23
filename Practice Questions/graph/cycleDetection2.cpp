/*
    Cycle detection in directed graph
    1) Using DFS
    2) Using BFS
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}

//Using DFS
bool DFSRec(vector<int> adj[], bool visited[], bool recurStack[], int st){
    visited[st] = true;
    recurStack[st] = true;
    for (int v :adj[st])
    {
        if (!visited[v])
        {
            if (DFSRec(adj, visited, recurStack, v) == true)
                return true;
        }
        else if (recurStack[v] == true)
            return true;
    }
    recurStack[st] = false;
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V];
    bool recurStack[V];
    fill(recurStack, recurStack + V, false);
    fill(visited, visited + V, false);

    for (int i=0;i<V;i++)
    {
        if (!visited[i] && DFSRec(adj, visited, recurStack, i) == true)
            return true;
    }
    return false;
}

//Using BFS 
void setIndegree(vector<int>adj[], int indegrees[], int V)
{
    for (int i=0;i<V;i++)
        for (int vertex:adj[i])
            indegrees[vertex]++;
}

bool BFSIte(vector<int> adj[], int V){

    int indegree[V];
    fill(indegree, indegree + V, 0);
    setIndegree(adj, indegree, V);
    queue<int> q;

    for (int i=0;i<V;i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
        count++;
    }
    return (count != V);
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    //addEdge(adj, 2, 0);
    //addEdge(adj, 4, 5);

    cout<<"Using DFS : "<<(DFS(adj, V) ? "Cycle Found" : "No Cycle Found")<<endl;
    cout<<"Using BFS : "<<(BFSIte(adj, V) ? "Cycle Found" : "No Cycle Found")<<endl;

    return 0;
}

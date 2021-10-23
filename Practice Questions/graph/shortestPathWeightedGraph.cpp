/*
    Given a weighted directed acyclic graph and a source vertex, find shortest distance of every vertex from source
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void setIndegree(vector<pair<int, int>> adj[], int indegree[], int V)
{
    for (int i=0;i<V;i++)
        for (pair<int,int> v:adj[i])
            indegree[v.first]++;
}

void topoSort(vector<pair<int, int>> adj[], int V, vector<int> &res)
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
        res.push_back(u);
        for (pair<int,int> v:adj[u])
        {
            indegree[v.first]--;
            if (indegree[v.first] == 0)
                q.push(v.first);
        }
    }
}

void shortestPath(vector<pair<int, int>> adj[], int V, int st)
{
    int dist[V];
    vector<int> vertexList; 
    fill(dist, dist + V, INT32_MAX);
    dist[st] = 0;

    topoSort(adj, V, vertexList);

    for (int u:vertexList){
        for (pair<int,int> v:adj[u])
            if (dist[v.first] - v.second > dist[u])
                dist[v.first] = dist[u] + v.second;
    }
    
    for (int d:dist)
        cout<<d<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int V = 6;
    vector<pair<int, int>> adj[V];

    //addEdge(adj, u, v, weight);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 5, 3, 1);

    shortestPath(adj, V, 4);

    return 0;
}

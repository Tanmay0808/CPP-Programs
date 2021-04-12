#include<iostream>
#include<vector>
using namespace std;

int primMST(vector<int> graph[], int V)
{
    int key[V], minCost = 0;
    bool mSet[V];
    fill(key, key + V, INT32_MAX);
    fill(mSet, mSet + V, false);
    //Weight for starting vertex will always be zero
    key[0] = 0;

    for (int count=0;count<V;count++)
    {
        int u = -1;
        //Find min weight vertex
        for (int i=0;i<V;i++)
        {
            if (!mSet[i] && (u==-1 || key[i] < key[u]))
                u = i;
        }

        //Include min weight vertex in MST set
        mSet[u] = true;
        minCost = minCost + key[u];

        //Update weights of adjacents of u
        for (int v=0;v<V;v++)
        {
            if (graph[u][v]!=0 && !mSet[v])
                key[v] = min(key[v], graph[u][v]);
        }
    }
    return minCost;
}

int main(int argc, char const *argv[])
{
    vector<int> graph[] = {{0,5,8,0},{5,0,10,15},{8,10,0,20},{0,15,20,0}};
    cout<<"Minimum Cost : "<<primMST(graph, 4)<<endl;
    return 0;
}

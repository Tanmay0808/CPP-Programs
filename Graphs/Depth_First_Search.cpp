#include<iostream>
using namespace std;

void DFS(int G[][8], int vertex,int n)
{
   static int visited[8] = {0};
   if (visited[vertex] == 0)
   {
      cout<<vertex<<"  ";
      visited[vertex] = 1;
      for (int v=1;v<n;v++)
      {
         if (G[vertex][v]==1 && visited[v]==0)
         {
            DFS(G,v,n);
         }
      }
   }
}

int main(){
   cout<<"DFS :  -- "<<endl;

   int G[8][8] = {{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,0,1,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0}};

   cout<<"\nDepth First Search : -- \n"<<endl;
   DFS(G,1,8);
   cout<<endl;

   return 0;
}


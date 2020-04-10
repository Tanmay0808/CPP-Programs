#include<iostream>
#include<limits.h>
#define I INT_MAX
using namespace std;

//ARRAY TO KEEP TRACK OF VISITED VERTICES
int near[8]={I,I,I,I,I,I,I,I};

//2-D ARRAY FOR STORING SELECTED EDGE VERTICES
int t[2][7];

//STORING GRAPH : COST ADJACENCY MATRIX
int cost[8][8] = {{I, I, I, I, I, I, I, I},
                  {I, I, 25, I, I, I, 5, I},
                  {I, 25, I, 12, I, I, I, 10},
                  {I, I, 12, I, 8, I, I, I},
                  {I, I, I, 8, I, 16, I, 14},
                  {I, I, I, I, 16, I, 20, 18},
                  {I, 5, I, I, I, 20, I, I},
                  {I, I, 10, I, 14, 18, I, I}};

void PrimsAlgo()
{
   int i,j,u,v,k,min=I,n=7,minCost = 0;

   //Step 1 : Find Minimum Edge And Store It In t
   for (i=1;i<=n;i++)
   {  for (j=i;j<=n;j++)
      {
         if (cost[i][j] < min)
         {
            min = cost[i][j];
            u = i;v = j;
         }
      }
   }
   t[0][0] = u; t[1][0] = v;
   near[u] = near[v] = 0;

   //Step 2 : Filling Near Array With Nearer Vertices
   for (i=1;i<=n;i++)
   {
      if (near[i]!=0)
      {
         if (cost[i][u] < cost[i][v])
            near[i] = u;
         else
            near[i] = v;
      }
   }

   //Step 3 : Repeating Step To Find All Edges
   for (i=1;i<n-1;i++)
   {
      min = I;
      //Finding Minimum And Connected From Rest Of Vertices
      for (j=1;j<=n;j++)
      {
         if (near[j]!=0 && cost[j][near[j]] < min)
         {
            min = cost[j][near[j]];
            k = j;
         }
      }

      //Storing Next Min In t
      t[0][i] = k; t[1][i] = near[k];
      near[k] = 0;

      //Comparing New Vertex Cost Edge With Existing Cost Edges
      for (j=1;j<=n;j++)
      {
         if (near[j]!=0 && cost[j][near[j]] > cost[j][k])
            near[j] = k;
      }
   }

   cout<<"\nMinimum Cost Vertices Pair Are : "<<endl;
   for (i=0;i<n-1;i++)
   {
      cout<<"( "<<t[0][i]<<" , "<<t[1][i]<<" )"<<endl;
      minCost += cost[t[0][i]][t[1][i]];
   }
   cout<<"\nMinimum Cost : "<<minCost<<endl;
}

int main()
{
   cout<<"PRIMS ALGORITHM : -- "<<endl;
   PrimsAlgo();

   return 0;
}

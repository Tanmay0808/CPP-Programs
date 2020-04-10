#include<iostream>
#include<limits.h>
#define I INT_MAX
using namespace std;


//ARRAY TO KEEP TRACK OF INCLUDED EDGES
int included[9]={0,0,0,0,0,0,0,0,0};

//SET S USED FOR CHECKING CYCLES
int s[8]={-1,-1,-1,-1,-1,-1,-1,-1};

//2-D ARRAY FOR STORING SELECTED EDGE VERTICES
int t[2][7];

//STORING GRAPH
int edges[3][9]={{1,1,2,2,3,4,4,5,5},
                 {2,6,3,7,4,5,7,6,7},
                 {25,5,12,10,8,16,14,20,18}};

//SET Functions That Will Help Us In Detecting Cycles
void unionSet(int u, int v)
{
   if (s[u] < s[v])
   {
      s[u] = s[u] + s[v];
      s[v] = u;
   }
   else
   {
      s[v] = s[u] + s[v];
      s[u] = v;
   }
}

int findParent(int v)
{
   int x = v;
   while (s[x] > 0)
   {
      x = s[x];
   }
   return x;
}

void KruskalAlgo()
{
   int i=0,j,u,v,k,min,n=7,e=9,minCost = 0;

   /*Repeating Steps : Find Minimum And Set Its Inclusion In Included Array
                       If Parents Are Different, Perform Union And Include Them
                       In Result i.e They Are Not Forming Cycle  */
   while (i<n-1)
   {
      min = I;

      //Finding Minimum Edge
      for (j=0;j<e;j++)
      {
         if (included[j]==0 && edges[2][j] < min)
         {
            min = edges[2][j];
            u = edges[0][j];
            v = edges[1][j];
            k = j;
         }
      }

      //Checking For Cycle
      if (findParent(u) != findParent(v))
      {
         t[0][i] = u; t[1][i] = v;
         unionSet(findParent(u),findParent(v));
         minCost += edges[2][k];
         i++;
      }
      included[k] = 1;
   }

   cout<<"\nMinimum Cost Vertices Pair Are : "<<endl;
   for (i=0;i<n-1;i++)
   {
      cout<<"( "<<t[0][i]<<" , "<<t[1][i]<<" )"<<endl;
   }
   cout<<"\nMinimum Cost : "<<minCost<<endl;
}

int main()
{
   cout<<"KRUSKALS ALGORITHM :  --"<<endl;
   KruskalAlgo();

   return 0;
}

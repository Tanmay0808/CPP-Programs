#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int adjacents[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
     int timeCnt = 0, n = grid.size(), m = grid[0].size(), nOnes=0;
     queue<pair<int, int>> q;
     
     for (int i=0;i<n;i++)
     {
         for (int j=0;j<m;j++)
         {
             if (grid[i][j] == 2)
             {
                 q.push(make_pair(i,j));
             }
             else if (grid[i][j] == 1) nOnes++;
         }
     }
     
     bool flg;
     while(!q.empty())
     {
         flg = false;
         int cnt = q.size();
         for (int i=0;i<cnt;i++)
         {
             pair<int, int> currCell = q.front();q.pop();
             for (int *p : adjacents)
             {
                 int new_i = currCell.first + p[0], new_j = currCell.second + p[1];
                 if ((new_i >=0 && new_i < n) && (new_j >=0 && new_j < m))
                 {
                     if (grid[new_i][new_j] == 1)
                     {
                         flg = true;
                         nOnes--;
                         grid[new_i][new_j] = 2;
                         q.push(make_pair(new_i,new_j));
                     }
                 }
             }
         }
         if (flg) timeCnt++;
     }
     return nOnes == 0 ? timeCnt : -1;
    }
};

int main(){
int tc;
cin >> tc;
while(tc--){
int n, m;
cin >> n >> m;
vector<vector<int>>grid(n, vector<int>(m, -1));
for(int i = 0; i < n; i++){
for(int j = 0; j < m; j++){
cin >> grid[i][j];
}
}
Solution obj;
int ans = obj.orangesRotting(grid);
cout << ans << "\n";
}
return 0;
}


/*
    Given a 2D grid of 0's(water) and 1's(land), count the no of islands
*/

#include<iostream>
#include<vector>
using namespace std;

int adjacents[8][2] = {{-1, 1},{0, 1},{1, 1},
                       {-1, 0},/* X */{1, 0},
                       {-1,-1},{0,-1},{-1,1}};

void markLandVisited(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row_i, int col_j)
{
    visited[row_i][col_j] = true;
    for (int *cell:adjacents)
    {
        int new_i = row_i + cell[0];
        int new_j = col_j + cell[1];
        if ((new_i>=0 && new_i<grid.size()) && (new_j >=0 && new_j<grid[0].size()))
        {
            if (grid[new_i][new_j] == 1 && visited[new_i][new_j] == false)
                markLandVisited(grid, visited, new_i, new_j);
        }
    }
}

int countIslands(vector<vector<int>> &grid)
{
    int isLands = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
    for (int i=0;i<grid.size();i++)
    {
        for (int j=0;j<grid[0].size();j++)
        {
            if (grid[i][j]==1 && visited[i][j]==false)
            {
                markLandVisited(grid, visited, i, j);
                isLands++;
            }
        }
    }
    return isLands;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};
    cout<<"No of islands : "<<countIslands(grid)<<endl;
    return 0;
}

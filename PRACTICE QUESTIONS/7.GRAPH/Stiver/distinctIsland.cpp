/*                                                 Number of Distinct Islands

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we
have only 1 distinct island.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &v, int Row, int Col)
{
    vis[row][col] = 1;
    v.push_back({row - Row, col - Col});

    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int r = row + drow[i];
        int c = col + dcol[i];

        if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1)
        {
            dfs(r, c, vis, grid, v, Row, Col);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> v;
                dfs(i, j, vis, grid, v, i, j);
                s.insert(v);
            }
        }
    }
    return s.size();
}

int main()
{

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
}
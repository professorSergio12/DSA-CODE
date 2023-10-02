/*                                            Number Of Enclaves
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
*/

#include <bits.stdc++.h>
using namespace std;

/*                                               BY USING DFS                                                     */
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int drow[], int dcol[])
{

    int n = grid.size();
    int m = grid[0].size();

    if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == 1)
    {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];

            dfs(r, c, vis, grid, drow, dcol);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    for (int i = 0; i < m; i++)
    {
        // check the first row if there is any 1 or not, if yes then marked it as visited
        if (!vis[0][i] && grid[0][i] == 1)
        {
            dfs(0, i, vis, grid, drow, dcol);
        }
        // check the last row if there is any 1 or not, if yes then marked it as  visited
        if (!vis[n - 1][i] && grid[n - 1][i] == 1)
        {
            dfs(n - 1, i, vis, grid, drow, dcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // check the first column if there is any 1 or not, if yes then marked it as visited
        if (!vis[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, vis, grid, drow, dcol);
        }
        // check the last column if there is any 1 or not, if yes then marked it as visited
        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
        {
            dfs(i, m - 1, vis, grid, drow, dcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check that if there is any 1 remaining in the matrix which is not visited, if yes then increase the count by 1
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

/*                                          BY USING BFS

Time Complexity: O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity ~ O(N x M), O(N x M) for the visited array, and queue space takes up N x M locations at max.
*/
int numberOfEnclaves(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};
    // traverse boundary elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // first row, first col, last row, last col
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                // if it is a land then store it in queue
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, +0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverses all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and for land cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check for unvisited land cell
            if (grid[i][j] == 1 & vis[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main()
{

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;
}
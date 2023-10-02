/*                           Find the number of islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, int visited[][501], vector<vector<char>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return;

        if (!visited[i][j])
        {
            visited[i][j] = 1;
            dfs(i - 1, j, visited, grid);
            dfs(i + 1, j, visited, grid);
            dfs(i, j + 1, visited, grid);
            dfs(i, j - 1, visited, grid);
            dfs(i + 1, j + 1, visited, grid);
            dfs(i - 1, j - 1, visited, grid);
            dfs(i + 1, j - 1, visited, grid);
            dfs(i - 1, j + 1, visited, grid);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int visited[501][501];
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, visited, grid);
                    c++;
                }
            }
        }
        return c;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
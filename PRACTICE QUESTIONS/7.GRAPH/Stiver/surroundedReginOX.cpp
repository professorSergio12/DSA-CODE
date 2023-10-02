/*                                             Replace O's with X's

Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'O', 'O'}}

Explanation: Following the rule the above
matrix is the resultant matrix.
*/

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int drow[], int dcol[])
    {
        vis[row][col] = 1;

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && mat[r][c] == 'O')
            {
                dfs(r, c, vis, mat, drow, dcol);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        for (int i = 0; i < m; i++)
        {
            if (!vis[0][i] && mat[0][i] == 'O')
            {
                dfs(0, i, vis, mat, drow, dcol);
            }

            if (!vis[n - 1][i] && mat[n - 1][i] == 'O')
            {
                dfs(n - 1, i, vis, mat, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, drow, dcol);
            }

            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, mat, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

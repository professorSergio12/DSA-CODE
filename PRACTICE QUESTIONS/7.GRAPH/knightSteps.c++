/*                                          Steps by Knight
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:The initial and the target position coordinates of Knight have been given according to 1-base indexing.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int x1 = KnightPos[0];
        int x2 = TargetPos[0];
        int y1 = KnightPos[1];
        int y2 = TargetPos[1];

        if (x1 == x2 && y1 == y2)
            return 0;
        queue<pair<int, int>> q;
        q.push({x1 - 1, y1 - 1}); // zero based indexing like we have given KnightPos[4, 5] we are taking KnightPos[3,4]

        vector<vector<int>> v(N, vector<int>(N, 0)); //visited vector
        v[x1 - 1][y1 - 1] = 0;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;

            // i-1,j-2;
            if (i - 1 >= 0 && j - 2 >= 0 && i - 1 < N && j - 2 < N && v[i - 1][j - 2] == 0)
            {
                v[i - 1][j - 2] = 1 + v[i][j];
                q.push({i - 1, j - 2});
            }

            // i-1,j+2;
            if (i - 1 >= 0 && j + 2 >= 0 && i - 1 < N && j + 2 < N && v[i - 1][j + 2] == 0)
            {
                v[i - 1][j + 2] = 1 + v[i][j];
                q.push({i - 1, j + 2});
            }

            // i+1,j-2;
            if (i + 1 >= 0 && j - 2 >= 0 && i + 1 < N && j - 2 < N && v[i + 1][j - 2] == 0)
            {
                v[i + 1][j - 2] = 1 + v[i][j];
                q.push({i + 1, j - 2});
            }

            // i+1,j+2;
            if (i + 1 >= 0 && j + 2 >= 0 && i + 1 < N && j + 2 < N && v[i + 1][j + 2] == 0)
            {
                v[i + 1][j + 2] = 1 + v[i][j];
                q.push({i + 1, j + 2});
            }

            // i+2,j+1;
            if (i + 2 >= 0 && j + 1 >= 0 && i + 2 < N && j + 1 < N && v[i + 2][j + 1] == 0)
            {
                v[i + 2][j + 1] = 1 + v[i][j];
                q.push({i + 2, j + 1});
            }

            // i-2,j-1;
            if (i - 2 >= 0 && j - 1 >= 0 && i - 2 < N && j - 1 < N && v[i - 2][j - 1] == 0)
            {
                v[i - 2][j - 1] = 1 + v[i][j];
                q.push({i - 2, j - 1});
            }

            // i-2,j+1;
            if (i - 2 >= 0 && j + 1 >= 0 && i - 2 < N && j + 1 < N && v[i - 2][j + 1] == 0)
            {
                v[i - 2][j + 1] = 1 + v[i][j];
                q.push({i - 2, j + 1});
            }

            // i+2,j-1;
            if (i + 2 >= 0 && j - 1 >= 0 && i + 2 < N && j - 1 < N && v[i + 2][j - 1] == 0)
            {
                v[i + 2][j - 1] = 1 + v[i][j];
                q.push({i + 2, j - 1});
            }
        }
        return v[x2 - 1][y2 - 1];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
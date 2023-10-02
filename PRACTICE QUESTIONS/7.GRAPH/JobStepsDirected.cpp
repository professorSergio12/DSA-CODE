/*                    Minimum time taken by each job to be completed given by a Directed Acyclic Graph

Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Example:

Input:
N=10
M=13
edges[]={{1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}}

Output:
time[]={1,1,2,2,2,3,4,5,2,6 }

Explanation:
Start jobs 1 and 2 at the beginning and complete them at 1 unit of time.
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly,
Job 6 can only be done after the 3rd and 4th jobs are done. So, start it at the 2nd unit of time and complete it at the 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at the 3rd unit of time and complete it at the 4th unit of time.
Job 8 can only be done after the 4th, 5th, and 7th jobs are done. So, start it at the 4th unit of time and complete it at the 5th unit of time.
Job 10 can only be done after the 8th job is done.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        queue<int> q;
        vector<int> indegree(n + 1, 0);
        vector<int> adj[n + 1]; // here we are creating graph
        vector<int> ans(n + 1, INT_MAX);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                ans[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            for (auto i : adj[s])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    ans[i] = ans[s] + 1;
                    q.push(i);
                }
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
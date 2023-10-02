/*                                                      Course Schedule

There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output "No Ordering Possible".

Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible order is [0, 1].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    vector<int> adj[V];

    for (auto x : prerequisites)
    {
        adj[x[1]].push_back(x[0]);
    }

    queue<int> q;
    vector<int> indegree(V, 0);
    vector<int> result;

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        result.push_back(s);

        for (auto i : adj[s])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return result;

    if (result.size() == V)
        return result;
    return {};
}

int main()
{
}
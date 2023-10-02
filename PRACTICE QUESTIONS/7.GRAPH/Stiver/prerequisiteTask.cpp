/*                                                       Prerequisite Tasks

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Example 1:

Input:
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should
have finished task 1, and to do task 3 you
should have finished task 2. So it is possible.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int V, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[V];

    for (auto x : prerequisites)
    {
        adj[x.first].push_back(x.second);
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
        return true;
    return false;
}

int main()
{
}
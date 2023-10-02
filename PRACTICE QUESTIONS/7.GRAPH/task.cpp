/*                                         Prerequisite Tasks

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Example :

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

class Solution
{
public:
    bool dfs(int V, vector<bool> &visited, vector<bool> &recS, vector<int> adj[])
    {
        visited[V] = true;
        recS[V] = true;

        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                if (dfs(i, visited, recS, adj))
                    return true;
            }
            else if (recS[i])
            {
                return true;
            }
        }
        recS[V] = false;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int>> &prereqs)
    {
        vector<bool> visited(N, false);
        vector<bool> recS(N, false);
        vector<int> adj[N];              //here we are creating graph 

        for (auto it : prereqs)
            adj[it.first].push_back(it.second);

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, recS, adj))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }

        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
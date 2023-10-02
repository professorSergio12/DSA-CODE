/*                                                   Detect cycle in a directed graph

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recS)
    {
        visited[V] = true;
        recS[V] = true;

        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recS))
                    return true;
            }
            else if (recS[i]) // if it value is already marked as true in recS then cycle is present
            {
                return true;
            }
        }
        recS[V] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> recS(V, false); // Recursion stack

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recS))  //if cycle is present return true
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

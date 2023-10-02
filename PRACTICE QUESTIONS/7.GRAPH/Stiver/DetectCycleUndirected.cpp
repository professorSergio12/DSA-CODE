/*                               Detect cycle in an undirected graph

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool dfs(int V, vector<int> adj[], vector<int> &visited, int parent)
    {
        visited[V] = true;

        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, V))
                    return true;
            }
            else if (parent != i)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

// USING BFS
void BFS(int src, vector<int> adj[], vector<bool> visited)
{
    visited[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!visited[adjNode])
            {
                q.push({adjNode, node});
                visited[adjNode] = 1;
            }
            else if (parent != adjNode)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (BFS(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
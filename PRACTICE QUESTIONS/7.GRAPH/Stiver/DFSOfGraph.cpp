/*                                            DFS of Graph

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V, vector<int> adj[], vector<int> &visited, vector<int> &ans)
    {
        ans.push_back(V);
        visited[V] = true;

        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> visited(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, adj, visited, ans);
        }
        return ans;
    }
};

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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
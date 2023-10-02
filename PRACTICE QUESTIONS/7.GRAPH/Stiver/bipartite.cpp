/*                  Bipartite Graph

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
*/

#include <bits/stdc++.h>
using namespace std;

/*                                        BY USING DFS                                                         */
bool dfs(int src, int color, vector<int> &col, vector<vector<int>> &graph)
{
    col[src] = color;

    for (auto x : graph[src])
    {
        if (col[x] == -1)
        {
            if (!dfs(x, !color, col, graph))
                return false;
        }

        else if (col[x] == color)
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> col(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
            if (!dfs(i, 0, col, graph))
                return false;
    }
    return true;
}
/*                                         BY USING BFS                                                 */

bool bfs(int src, vector<int> &col, vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(src);
    col[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto x : graph[node])
        {
            // if the adjacent node is yet not colored so we have to give the opposite color to the node
            if (col[x] == -1)
            {
                col[x] = !col[node];
                q.push(x);
            }

            else if (col[x] == col[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> col(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
            if (!bfs(i, col, graph))
                return false;
    }
    return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends
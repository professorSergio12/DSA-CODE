/*                               Strongly Connected Components (Kosaraju's Algo)

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> order;

    void dfs(int src, vector<int> &visited, vector<int> adj[])
    {
        visited[src] = 1;
        for (auto x : adj[src])
        {
            if (!visited[x])
            {
                dfs(x, visited, adj);
            }
        }
        order.push_back(src);
    }

    void rdfs(int src, vector<int> &vis, vector<int> rev[])
    {
        vis[src] = 1;
        for (auto x : rev[src])
        {
            if (!vis[x])
            {
                rdfs(x, vis, rev);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        order.clear();
        vector<int> rev[V];

        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                rev[j].push_back(i);
            }
        }

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
            }
        }

        vector<int> vis(V, 0);
        int count = 0;
        for (int i = V - 1; i >= 0; i--)
        {
            if (!vis[order[i]])
            {
                rdfs(order[i], vis, rev);
                count++;
            }
        }
        return count;
    }
};

/*                                              BY USING STACK                                     */
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// Expected Time Complexity: O(V+E).
// Expected Auxiliary Space: O(V).
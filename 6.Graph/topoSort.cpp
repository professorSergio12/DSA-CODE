/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

*/

//  NOTE:- The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
#include <bits/stdc++.h>
using namespace std;

/*                                                KAHN'S ALGORITHM                                   */
void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
}

vector<int> topological_sort(int V, vector<int> adj[])
{
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
}

// 2ND APPROACH

void dfs(int src, vector<int> &vis, stack<int> st, vector<int> adj[])
{
    vis[src] = 1;

    for (auto x : adj[src])
    {
        if (!vis[i])
        {
            dfs(x, vis, s, adj);
        }
    }
    s.push(src);
}

vector<int> topological_sort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        ans.push_back(node);
    }
    return ans;
}

int main()
{
    int size = 5;
    vector<int> graph[size];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    vector<int> result = topological_sort(size, graph);
    if (result.size() != size)
        cout << "Topological sort not possible" << endl;
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// or

class Solution
{
public:
    void dfs(int V, vector<int> &visited, stack<int> &st, vector<int> adj[])
    {

        visited[V] = 1;
        for (auto i : adj[V])
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        st.push(V);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> visited(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }

        while (!st.empty())
        {
            int s = st.top();
            ans.push_back(s);
            st.pop();
        }
        return ans;
    }
};

int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int V = 7;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(V, false);
    stack<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int s = q.top();
        cout << s << " ";
        q.pop();

        for (auto i = graph[s].begin(); i != graph[s].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main()
{
    vector<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "DFS traversal starting from node 0:"
         << " ";
    bfs(graph, 0);
}
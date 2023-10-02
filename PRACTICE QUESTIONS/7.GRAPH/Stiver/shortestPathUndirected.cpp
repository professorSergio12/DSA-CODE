/*                               Shortest path in Undirected Graph having unit distance

You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]
src = 0
Output:
0 1 2 1 2 3 3 4 4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // A dist array of size N initialised with a large number to
    // indicate that initially all the nodes are untraversed.

    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;
    // BFS Implementation.
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }
    // Updated shortest distances are stored in the resultant array ‘ans’.
    // Unreachable nodes are marked as -1.
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++)
    {
        if (dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
    }
    return ans;
}

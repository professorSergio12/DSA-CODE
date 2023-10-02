/*                      Distance from the Source (Bellman-Ford Algorithm)

Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
*/

// NOTE: The Graph doesn't contain any negative weight cycle.
#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
{
    vector<int> dist(V, 100000000);
    dist[S] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto it : adj)
        {
            if (dist[it[0]] + it[2] < dist[it[1]])
            {
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }
    return dist;
}

/*
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.


Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3.
*/

int isNegativeWeightCycle(int V, vector<vector<int>> adj)
{
    vector<int> dist(V, 1e6);
    dist[0] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto it : adj)
        {
            if (dist[it[0]] + it[2] < dist[it[1]])
            {
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }

    for (auto it : adj)
    {
        if (dist[it[0]] + it[2] < dist[it[1]])
        {
            return 1;
        }
    }

    return 0;
}

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}
/*

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)


*/
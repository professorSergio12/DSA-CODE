/*                                                             Eventual Safe States
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/

#include <bits./stdc++.h>
using namespace std;

bool dfs(int src, int vis[], int recS[], int check[], vector<int> &ans, vector<int> adj[])
{
    vis[src] = 1;
    recS[src] = 1;
    check[src] = 0;

    for (auto x : adj[src])
    {
        if (!vis[i])
        {
            if (dfs(x, vis, recS, check, ans, adj))
            {
                check[x] = 0;
                return true;
            }
        }

        else if (recS[x])
            check[x] = 0;
        return true;
    }

    check[src] = 1;
    recS[src] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int recS[V] = {0};
    int check[V] = {0}; // use for marking a node is safe or not
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, recS, check, ans, adj);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
            ans.push_back(i);
    }
    return ans;
}
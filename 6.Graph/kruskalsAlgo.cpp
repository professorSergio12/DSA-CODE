
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
}

int find(int x, int parent[]) // here find = to check the representative of a set
{
    // UNION BY RANK
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

// The Union-Find algorithm divides the vertices into clusters and allows us to check if two vertices belong to the same cluster or not and hence decide whether adding an edge creates a cycle.
void union_(int a, int b, int parent[], int rank[]) // here union = to make the friends
{
    int xRoot = find(a, parent);
    int yRoot = find(b, parent);

    if (rank[xRoot] < rank[yRoot])
    {
        parent[xRoot] = yRoot;
    }

    else if (rank[xRoot] > rank[yRoot])
    {
        parent[yRoot] = xRoot;
    }

    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            int node = x[0];
            int wt = x[1];
            pq.push({wt, {i, node}});
        }
    }

    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int ans = 0;
    while (!pq.empty())
    {
        auto x = pq.top();
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        pq.pop();
        if (find(u, parent) != find(v, parent)) // if there representative are not same then find union
        {
            ans += wt;
            union_(u, v, parent, rank);
        }
    }
    return ans;
}

int main()
{
}

// Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

// Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).
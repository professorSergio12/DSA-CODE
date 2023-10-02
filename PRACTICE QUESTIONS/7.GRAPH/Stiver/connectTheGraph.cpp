/*                                        Connecting the graph

You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.
Find the minimum number of operation that will be required to make the graph connected.
If it is not possible to make the graph connected, return -1.

Example 1:

Input:
n=4
m=3
Edge=[ [0, 1] , [0, 2] , [1, 2] ]

Output:
1

Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
*/

#include <bits/stdc++.h>
using namespace std;

int find(int x, int parent[])
{
    if (x == parent[x])
        return x;
    else
        parent[x] = find(parent[x], parent);
}

void unions(int a, int b, int parent[], int rank[])
{
    int X = find(a, parent);
    int Y = find(b, parent);

    if (X != Y)
    {
        if (rank[X] > rank[Y])
        {
            parent[Y] = X;
        }
        else if (rank[Y] > rank[X])
        {
            parent[X] = Y;
        }
        else
        {
            parent[Y] = X;
            rank[X]++;
        }
    }
}

int Solve(int n, vector<vector<int>> &edge)
{
    int parent[n];
    int rank[n] = {0};

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cntExtras = 0;

    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];
        if (find(u, parent) == find(v, parent))
        {
            cntExtras++;
        }
        else
        {
            unions(u, v, parent, rank);
        }
    }

    int cntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            cntC++;
    }

    int ans = cntC - 1;
    if (cntExtras >= ans)
        return ans;

    return -1;
}
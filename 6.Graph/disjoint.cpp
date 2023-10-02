/*                        UNION BY RANK AND BY PATH COMPRESSION
This problem is to implement disjoint set union. There will be 2 incomplete functions namely union and find. You have to complete these functions.

Union: Join two subsets into a single set.
isConnected: Determine which subset a particular element is in. This can be used for determining if two elements are in same subset.

Example 1:

Input:
N = 5
q = 4
Queries =
Union(1,3)
isConnected(1,2)
Union(1,5)
isConnected(3,5)
Output:
0
1
Explanation: Initially all nodes 1 2 3 4 5
are not connected.
After Union(1,3), node 1 and 3 will be
connected.
When we do isConnected(1,2),  as node 1
and 2 are not connected it will return 0.
After Union(1,5), node 1 and 5 will be
connected.
When we do isConnected(3,5),  as node
1 and 3 are connected, and node 1 and 5
are connected, hence 3 and 5 are
connected. Thus it will return 1.

*/
#include <bits/stdc++.h>
using namespace std;

int find(int x, int parent[]) // here find = to check the representative of a set
{
    // UNION BY RANK
    if (parent[x] == x)
    {
        return x;
    }
    return find(parent[x], parent);

    // UNION BY PATH COMPRESSION

    if (parent[x] != x)
    {
        parent[x] = find(parent[x],parent);
    }
    return parent[x];
}

void union_(int a, int b, int parent[], int rank[]) // here union= to make the friends
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

// Function to check whether 2 nodes are connected or not.
bool isConnected(int x, int y, int par[], int rank1[])
{
    if (find(x, par) == find(y, par))
    {
        return true;
    }
    return false;
}
int main()
{
}
/*                                        Graph Coloring
Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints.

Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color. The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same color) and Face Coloring (Geographical Map Coloring) can be transformed into vertex coloring.

Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 2 colors.

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res[v];        // resultant array used to check which colour we are using for particular index
    bool available[v]; // it is use to check whether the colour is available or not
    res[0] = 0;        // here we colour the 0th index with 0 colour

    for (int i = 1; i < v; i++) // initializing the resultant array with -1
        res[i] = -1;

    for (int i = 0; i < v; i++)
        available[i] = false; //  initializing the available array with false

    int cn = 0; // chromatic number  initializing with 0;
    for (int i = 1; i < v; i++)
    {
        for (auto x : g[i])
        {
            if (res[x] != -1) // if the the adjacent i is not equal to -1, it means that it is already coloured
            {
                available[res[x]] = true; // it means that colour is not available at that moment
            }
        }

        int cr;
        for (cr = 0; cr < v; cr++)
        {
            if (available[cr] == false) // in this we check rest of the colour which are available
            {
                break;
            }
        }

        res[i] = cr;          // 1st colour which is available we put that colour in our result array
        cn = max(cn, cr + 1); // here we are adding 1 beacuse we are using 0 based indexing(start indexing with 0,1,2...)

        for (auto x : g[i]) // this loop is used  for reseting the colour for net iteration
        {
            if (res[x] != -1)
            {
                available[res[x]] = false;
            }
        }
    }
    cout << cn << endl;
    for (int i = 0; i < v; i++)
        cout << res[i] << " ";
}

int main()
{

    solve();
    return 0;
}

// Time complexity: O(n^2)
// Space complexity:O(V)

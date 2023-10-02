/*                                       Journey to the Moon

The member states of the UN are planning to send 2  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example

n = 4;
astonaut=[1,2] [2,3]

There are 4 astronauts numbered 0 through 3. Astronauts grouped by country are [0] and [1,2,3]. There are 3 pairs to choose from: [0,1] , [0,2]and [0,3].
*/

#include <bits/stdc++.h>
#define int long long int
using namespace std;

void dfs(int src, vector<int> &vis, vector<int> g[], int &counter)
{
    vis[src] = 1;
    counter++;
    for (auto x : g[src])
    {
        if (!vis[x])
        {
            dfs(x, vis, g, counter);
        }
    }
}

int32_t main()
{

    int v, e;
    cin >> v >> e;
    vector<int> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> solution;
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            int counter = 0;
            dfs(i, vis, g, counter);
            solution.push_back(counter);
        }
    }
    int val = (v * (v - 1)) / 2;
    for (int i = 0; i < solution.size(); i++)
    {
        int x = (solution[i] * (solution[i] - 1)) / 2;
        val = val - x;
    }
    cout << val;

    return 0;
}

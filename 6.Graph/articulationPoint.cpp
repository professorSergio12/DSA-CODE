/*                                    TARJAN'S   ALGORITHM
*/
#include <bits/stdc++.h>
using namespace std;


int time = 0;

void find_articulation_points(vector<int> graph[], vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> &parent, set<int> &result, int v)
{
    visited[v] = true;
    time++;
    disc[v] = low[v] = time;
    int child = 0;
    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        int av = *i;
        if (visited[av] == false)
        {
            child++;
            parent[av] = v;
            find_articulation_points(graph, disc, low, visited, parent, result, av);
            low[v] = min(low[v], low[av]);
            if (parent[v] == -1 and child > 1)
                result.emplace(v);
            else if (parent[v] != -1 and low[av] >= disc[v])
                result.emplace(v);
        }
        else if (av != parent[v])
            low[v] = min(low[v], disc[av]);
    }
}
vector<vector<int>> criticalConnections(int V, vector<vector<int>> &connections)
{
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    vector<int> low(V, 0);
    vector<int> disc(V, 0);
    vector<vector<int>> ans;
    vector<int> graph[V];

    for (auto it : connections)
    {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    find_articulation_points(graph, disc, low, visited, parent, ans, V);
    return ans;
}

int main()
{
}
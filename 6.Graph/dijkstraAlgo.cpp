/*                              Implementing Dijkstra Algorithm
Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
*/

#include <bits/stdc++>
using namespace std;

/*                               By using PRIORITY_QUEUE                                    */
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> visited(V, false);

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int fst = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (visited[fst])
        {
            continue;
        }

        visited[fst] = true;

        for (auto &it : adj[fst])
        {
            int nexT_dst = wt + it[1];
            if (nexT_dst < dist[it[0]])
            {
                dist[it[0]] = nexT_dst;

                pq.push({nexT_dst, it[0]});
            }
        }
    }
    return dist;
}

/*                                   By using SET                                          */
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Create a set ds for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    // set stores the nodes in ascending order of the distances
    set<pair<int, int>> st;

    // Initialising dist list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> dist(V, 1e9);

    st.insert({0, S});

    // Source initialised with dist=0
    dist[S] = 0;

    // Now, erase the minimum distance node first from the set
    // and traverse for all its adjacent nodes.
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        // Check for all adjacent nodes of the erased
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgW = it[1];

            if (dis + edgW < dist[adjNode])
            {
                // erase if it was visited previously at
                // a greater cost.
                if (dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                // If current distance is smaller,
                // push it into the queue
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return dist;
}

int main()
{
}
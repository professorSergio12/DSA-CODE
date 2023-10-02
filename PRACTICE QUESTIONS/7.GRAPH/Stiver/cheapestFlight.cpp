/*                                       Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

class Solution
{
public:
    const int inf = 1e9;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> prize(n, inf);
        prize[src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            vector<int> TempPrize(n, inf);
            TempPrize = prize;

            for (auto edge : flights)
            {
                int v = edge[0];
                int u = edge[1];
                int wt = edge[2];

                if (prize[v] + wt < TempPrize[u])
                {
                    TempPrize[u] = prize[v] + wt;
                }
            }
            prize = TempPrize;
        }

        int ans = prize[dst];
        if (ans == inf)
            ans = -1;
        return ans;
    }
    /*                                    By using queue                                      */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, dist}} with 'stops' indicating
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        // Distance array to store the updated distances from the source.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with
        // popping out the element with min stops first.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop the process as soon as the limit for the stops reaches.
            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        // If the destination node is unreachable return '-1'
        // else return the calculated dist from src to dst.
        if (dist[dst] == 1e9)
            return -1;
            
        return dist[dst];
    }
};
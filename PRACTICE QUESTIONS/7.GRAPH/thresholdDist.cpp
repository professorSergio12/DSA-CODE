/*                       City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

Note: that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

Input:
N=4,M=4
edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
distanceThreshold = 4
Output:3
Explaination:The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;


        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= cntCity)
            {
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

int main()
{

    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    Solution obj;
    int cityNo = obj.findCity(n, m, edges, distanceThreshold);
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}

// Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

// Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
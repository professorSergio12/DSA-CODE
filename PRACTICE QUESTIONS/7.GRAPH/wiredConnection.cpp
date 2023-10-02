/*                        Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

EXAMPLE
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &adj, int it, vector<bool> &visited)
    {
        queue<int> q;
        q.push(it);
        visited[it] = true;
        while (!q.empty())
        {
            int s = q.front();
            q.pop();

            for (auto i : adj[s])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);            //here we are creating graph

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                bfs(adj, i, visited);
            }
        }
        return count - 1;
    }
};

// OR


// class Solution {
// public:
    
//     void dfs(int v, vector<int> &visited, vector<int> adj[])
//     {
//         visited[v] = 1;
        
//         for(auto i: adj[v])
//         {
//             if(!visited[i])
//             {
//                 dfs(i, visited, adj);
//             }
//         }
//     }
    
//     int makeConnected(int n, vector<vector<int>>& edges) {
       
//         vector<int>visited(n,0);
//         vector<int>adj[n];
//         int m = edges.size();
        
//         if(m< n-1)  return -1;
        
//         for(int i=0; i < m; i++)
//         {
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         int count=0;
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 count++;
//                 dfs(i, visited, adj);
        
//             }
//         }
//         return count-1;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

#define V 5
void addEdges(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
}

int main()
{
    int graph[V][V] = {0};

    addEdges(graph, 0, 1);
    addEdges(graph, 0, 4);
    addEdges(graph, 1, 1);
    addEdges(graph, 1, 2);
    addEdges(graph, 1, 3);
    addEdges(graph, 1, 4);
    addEdges(graph, 3, 2);
    addEdges(graph, 3, 4);

    cout << "Adjacency matrix: " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << "  ";
        cout << endl;
    }
}
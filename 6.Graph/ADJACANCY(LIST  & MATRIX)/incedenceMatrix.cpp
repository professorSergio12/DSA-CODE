#include <bits/stdc++.h>
using namespace std;

#define V 5
#define E 8
void addEdges(int graph[][E], int u, int v, int e)
{
    graph[u][e] = 1;
    if (u != v)
    {
        graph[v][e] = -1;
    }
}

int main()
{
    // 2d graph of V*E
    int graph[V][E] = {0};

    // graph, start, end, edge
    addEdges(graph, 0, 1, 0);
    addEdges(graph, 0, 4, 1);
    addEdges(graph, 1, 4, 2);
    addEdges(graph, 1, 3, 3);
    addEdges(graph, 1, 1, 5);
    addEdges(graph, 1, 2, 6);
    addEdges(graph, 3, 4, 4);
    addEdges(graph, 3, 2, 7);

    cout << "Incidence Matrix: " << endl;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
            cout << graph[i][j] << "  ";
        cout << endl;
    }
    return 0;
}
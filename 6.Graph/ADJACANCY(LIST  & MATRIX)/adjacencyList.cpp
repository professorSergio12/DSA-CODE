
#include <bits/stdc++.h>
using namespace std;

#define V 5
void addEdges(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v); // This function is used to insert a new element into the vector container, the new element is added to the end of the vector.
}

int main()
{
    int V;
    cout << "Enter The number of vertex: " << endl;
    cin >> V;
    vector<int> graph[V];

    addEdges(graph, 0, 1);
    addEdges(graph, 0, 4);
    addEdges(graph, 1, 1);
    addEdges(graph, 1, 2);
    addEdges(graph, 1, 3);
    addEdges(graph, 1, 4);
    addEdges(graph, 3, 2);
    addEdges(graph, 3, 4);

    cout << "Adjacency List : " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
            cout << " -> " << graph[i][j];
        cout << endl;
    }
}
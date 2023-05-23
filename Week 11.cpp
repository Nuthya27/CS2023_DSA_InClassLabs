#include <iostream>;
using namespace std;

#define vertices_count 6

int minEdge(int key[], bool mst_set[])
{
    int min = INT_MAX, index;
    for (int i = 0; i < vertices_count; i++)
        if (mst_set[i] == false && key[i] < min)
            min = key[i], index = i;
    return index;
}

void printMST(int parent[], int graph[vertices_count][vertices_count])
{
    cout << "Edge \tCost\n";
    for (int j = 1; j < vertices_count; j++)
        cout << parent[j] << " - " << j << " \t"
        << graph[j][parent[j]] << " \n";
}

void primsMST(int graph[vertices_count][vertices_count])
{
    int p[vertices_count];
    int key[vertices_count];
    bool mst_set[vertices_count];

    for (int k = 0; k < vertices_count; k++)
        key[k] = INT_MAX, mst_set[k] = false;

    key[0] = 0;
    p[0] = -1;

    for (int c = 0; c < vertices_count - 1; c++) {
        int u = minEdge(key, mst_set);
        mst_set[u] = true;
        for (int v = 0; v < vertices_count; v++)
            if (graph[u][v] && mst_set[v] == false
                && graph[u][v] < key[v])
                p[v] = u, key[v] = graph[u][v];
    }
    printMST(p, graph);
}

int main()
{
    int tp_graph[vertices_count][vertices_count] = { { 0, 3, 0, 6, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    primsMST(tp_graph);
    return 0;
}

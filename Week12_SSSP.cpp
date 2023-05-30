#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()


int findMinDistance(const vector<int>& distances, const vector<bool>& visited, int numNodes) {
    int minDistance = INF;
    int minIndex = -1;

    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i] && distances[i] <= minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}


void printPath(const vector<int>& parent, int target) {
    if (parent[target] == -1) {
        cout << target << "  ";
        return;
    }

    printPath(parent, parent[target]);
    cout << target << "  ";
}


void dijkstra(const vector<vector<int>>& graph, int source) {
    int numNodes = graph.size();

    vector<int> distances(numNodes, INF);  
    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);      

    distances[source] = 0; 

    for (int count = 0; count < numNodes - 1; ++count) {
        int u = findMinDistance(distances, visited, numNodes);
        visited[u] = true;

        for (int v = 0; v < numNodes; ++v) {
            if (!visited[v] && graph[u][v] && distances[u] != INF &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": ";
        cout << "Time = " << distances[i] << "   Path = ";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int numNodes = 6;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    graph = { {0,10,0,0,15,5},
              {10,0,10,30,0,0},
              {0,10,0,12,5,0},
              {0,30,12,0,0,20},
              {15,0,5,0,0,0}, 
              {5,0,0,20,0,0} };
    
    int source=0;

    dijkstra(graph, source);

    return 0;
}
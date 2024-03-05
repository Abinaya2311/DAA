#include <iostream>
#include <climits>

#define MAX_NODES 100
#define INF 9999

using namespace std;

struct Graph {
    int nodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
};

int minKey(int key[], bool mstSet[], int nodes) {
    int min = INF, minIndex;
    for (int v = 0; v < nodes; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void prim(Graph *graph) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];

    for (int i = 0; i < graph->nodes; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->nodes - 1; count++) {
        int u = minKey(key, mstSet, graph->nodes);
        mstSet[u] = true;

        for (int v = 0; v < graph->nodes; v++) {
            if (graph->adjacencyMatrix[u][v] && !mstSet[v] && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < graph->nodes; i++) {
        cout << parent[i] << " - " << i << "\t" << graph->adjacencyMatrix[i][parent[i]] << endl;
    }
}

int main() {
    Graph graph = {
        .nodes = 5,
        .adjacencyMatrix = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        }
    };

    prim(&graph);

    return 0;
}

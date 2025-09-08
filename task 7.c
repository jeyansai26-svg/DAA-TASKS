#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices

// Function to find the vertex with the minimum key value that is not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values to pick the minimum weight edge in the cut
    int mstSet[V]; // To represent vertices not yet included in MST
    int count, i, v;

    // Initialize all keys as INFINITE and mstSet[] as false
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1; // Initialize parent[] array with -1
    }

    // Always include the first vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet);

        // Include the picked vertex in the MST set
        mstSet[u] = 1;

        // Update the key and parent values of the adjacent vertices of the picked vertex
        for (v = 0; v < V; v++) {
            // Update the key only if graph[u][v] is non-zero, mstSet[v] is false,
            // and the weight of edge u-v is smaller than the current key of v
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Let us create the following graph:
    //        2    3
    //   (0)--(1)--(2)
    //    |   / \   |
    //   6| 8/   \5 |7
    //    | /     \ |
    //   (3)-------(4)
    //    9
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call the function to construct the MST
    primMST(graph);

    return 0;
}

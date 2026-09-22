/* Question: Greedy Method - Kruskal's Algorithm
Write a C program to implement Kruskal's Algorithm using the Greedy approach to find the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.
Kruskal's Algorithm:
1. Sort all edges in increasing order of their weights.
2. Select the edge with the smallest weight.
3. Add the edge to MST only if it does not form a cycle.
4. Repeat until (V - 1) edges are selected. 
*/
#include <stdio.h>

#define MAX 100

struct Edge {
    int src;
    int dest;
    int weight;
};

int parent[MAX];

// Find parent
int find(int i) {
    while (parent[i] != i)
        i = parent[i];

    return i;
}

// Union two sets
void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    parent[xroot] = yroot;
}

int main() {

    int V, E;
    struct Edge edges[MAX];
    struct Edge temp;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter source, destination and weight of each edge:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    // Sort edges according to weight
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {

            if (edges[j].weight > edges[j + 1].weight) {

                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int count = 0;
    int cost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E && count < V - 1; i++) {

        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        // Add edge only if it does not create a cycle
        if (x != y) {

            printf("%d - %d : %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            cost += edges[i].weight;

            unionSet(x, y);

            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}

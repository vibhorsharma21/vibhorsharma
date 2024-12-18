#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 10

typedef struct Edge {
    int u, v, weight;
} Edge;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Edge edges[MAX_EDGES];
Subset subsets[MAX_VERTICES];
int numVertices, numEdges;

int find(int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets[i].parent);  // Path compression
    }
    return subsets[i].parent;
}

void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal() {
    int mstWeight = 0;
    int mstEdges = 0;

    qsort(edges, numEdges, sizeof(Edge), compareEdges);  // Sort edges by weight

    // Initialize subsets for each vertex
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (find(u) != find(v)) {
            printf("%d - %d: %d\n", u, v, weight);
            mstWeight += weight;
            unionSets(u, v);
            mstEdges++;
        }
        if (mstEdges == numVertices - 1) {
            break;
        }
    }

    printf("\nTotal weight of MST: %d\n", mstWeight);
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    if (numEdges == 0) {
        printf("No edges to process.\n");
        return 0;
    }

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        
        // Validate that the vertices are within range
        if (edges[i].u < 0 || edges[i].u >= numVertices || edges[i].v < 0 || edges[i].v >= numVertices) {
            printf("Invalid edge: %d %d\n", edges[i].u, edges[i].v);
            i--;  // Retry the same edge input
        }
    }

    kruskal();
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define INF 99999
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int minKey(int key[], int visited[], int V) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(int V) {
    int parent[V];
    int key[V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited, V);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d   %d\n", parent[i], i, graph[i][parent[i]]);
    }
}
int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }  prim(V);
return 0;}

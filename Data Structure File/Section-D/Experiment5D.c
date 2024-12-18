#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
#define INF 99999
int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int minDistance(int V) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;}
    } return minIndex;
}

void dijkstra(int V, int source) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    } dist[source] = 0;
        for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V);
        visited[u] = 1;
         for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] <   dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
          }}}
 printf("Vertex   Distance from Source   Path\n");
    for (int i = 0; i < V; i++) {
        if (i != source) {
            printf("%d \t\t %d \t\t\t ", i, dist[i]);
            int j = i;
            while (parent[j] != -1) {
                printf("%d <- ", j);
                j = parent[j]; }
            printf("%d\n", source);
        }
    }
}

int main() {
    int V, source;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }printf("Enter the source vertex: ");
    scanf("%d", &source);
   dijkstra(V, source);
   return 0;}
   

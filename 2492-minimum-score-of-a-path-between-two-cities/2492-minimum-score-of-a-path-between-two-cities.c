#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Edge {
    int to;
    int distance;
    struct Edge* next;
} Edge;

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    Edge** graph = (Edge**)calloc((n + 1), sizeof(Edge*));

    for(int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int dist = roads[i][2];

        Edge* edge1 = (Edge*)malloc(sizeof(Edge));
        edge1->to = v;
        edge1->distance = dist;
        edge1->next = graph[u];
        graph[u] = edge1;

        Edge* edge2 = (Edge*)malloc(sizeof(Edge));
        edge2->to = u;
        edge2->distance = dist;
        edge2->next = graph[v];
        graph[v] = edge2;
    }

    // BFS configuration
    bool* visited = (bool*)calloc((n + 1), sizeof(bool));
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int head = 0, tail = 0;

    queue[tail++] = 1;
    visited[1] = true;

    int min_score = INT_MAX;

    while(head < tail) {
        int curr = queue[head++];

        Edge* edge = graph[curr];
        while(edge != NULL) {
            if (edge->distance < min_score) {
                min_score = edge->distance;
            }

            if (!visited[edge->to]) {
                visited[edge->to] = true;
                queue[tail++] = edge->to;
            }
            edge = edge->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        Edge* edge = graph[i];
        while (edge != NULL) {
            Edge* tmp = edge;
            edge = edge->next;
            free(tmp);
        }
    }

    free(graph);
    free(visited);
    free(queue);

    return min_score;
}
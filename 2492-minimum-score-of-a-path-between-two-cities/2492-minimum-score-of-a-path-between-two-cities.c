#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Find operation with path compression
int find_set(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent, parent[i]);
}

// Union operation
void union_sets(int* parent, int i, int j) {
    int root_i = find_set(parent, i);
    int root_j = find_set(parent, j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    // Allocate and initialize parent array (1-indexed)
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // Step 1: Union all connected cities together
    for (int i = 0; i < roadsSize; i++) {
        union_sets(parent, roads[i][0], roads[i][1]);
    }
    
    // Find the root component group containing city 1
    int root1 = find_set(parent, 1);
    int min_score = 1e9; // Initialize with a large infinity value
    
    // Step 2: Scan all edges; if an edge belongs to city 1's component, track its minimum weight
    for (int i = 0; i < roadsSize; i++) {
        if (find_set(parent, roads[i][0]) == root1) {
            min_score = MIN(min_score, roads[i][2]);
        }
    }
    
    free(parent);
    return min_score;
}
void dfs(char** grid, int m, int n, int r, int c) {
    // Boundary checks and checking if the current cell is water ('0')
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
        return;
    }

    // Mark the current land as visited by turning it into water
    grid[r][c] = '0';

    // Visit all 4 neighbors
    dfs(grid, m, n, r - 1, c); // Up
    dfs(grid, m, n, r + 1, c); // Down
    dfs(grid, m, n, r, c - 1); // Left
    dfs(grid, m, n, r, c + 1); // Right
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;

    int m = gridSize;
    int n = gridColSize[0];
    int islands = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == '1') {
                islands++;
                // Start DFS to "sink" the entire island
                dfs(grid, m, n, r, c);
            }
        }
    }

    return islands;
}
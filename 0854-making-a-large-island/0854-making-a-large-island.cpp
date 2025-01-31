class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandID = 2; // Start IDs from 2 (since 0 and 1 are already used)
        unordered_map<int, int> islandSizes; // Maps island ID to its size

        // Step 1: Assign unique IDs to islands and calculate their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandID);
                    islandSizes[islandID] = size;
                    islandID++;
                }
            }
        }

        // Step 2: Find the maximum island size after changing one 0 to 1
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    int currentSize = 1; // Start with the current cell (0 -> 1)

                    // Check all four neighbors
                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
                            int neighborID = grid[x][y];
                            if (neighboringIslands.find(neighborID) == neighboringIslands.end()) {
                                neighboringIslands.insert(neighborID);
                                currentSize += islandSizes[neighborID];
                            }
                        }
                    }

                    maxSize = max(maxSize, currentSize);
                }
            }
        }

        // Edge case: If there are no 0s, the entire grid is one island
        if (maxSize == 0) {
            return n * n;
        }

        return maxSize;
    }

private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // DFS to assign IDs and calculate island sizes
    int dfs(vector<vector<int>>& grid, int i, int j, int islandID) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = islandID; // Assign the island ID
        int size = 1;

        for (auto& dir : directions) {
            size += dfs(grid, i + dir[0], j + dir[1], islandID);
        }

        return size;
    }
};
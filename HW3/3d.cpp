// Refrenced ashish_madhup
class Solution {
public:
    // DFS function to find all the cells in the island starting from (i, j)
    void dfs(vector<vector<int>>& grid, set<pair<int, int>>& island, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1 || island.count({i, j}))
            return;

        island.insert({i, j}); // Mark cell as part of island
        grid[i][j] = 2; // Mark cell as visited

        // Continue DFS to see rest of island
        dfs(grid, island, i + 1, j);
        dfs(grid, island, i - 1, j);
        dfs(grid, island, i, j + 1);
        dfs(grid, island, i, j - 1);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int, int>> island1, island2; // stores islands
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // tracks vistied 
        int found = 0; // check if both islands are found

        // DFS to find both islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (found == 0) {
                        dfs(grid, island1, i, j); // found first island
                        found++;
                    } else {
                        dfs(grid, island2, i, j); // found second island
                    }
                }
            }
        }

        int shortestDistance = INT_MAX; 
        // Calculate the distance between all cells and finds shprtest
        for (auto i : island1) {
            for (auto j : island2) {
                int distance = abs(i.first - j.first) + abs(i.second - j.second) - 1;
                shortestDistance = min(shortestDistance, distance);
            }
        }

        return shortestDistance;
    }
};

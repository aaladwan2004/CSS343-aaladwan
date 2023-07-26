class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        // cases for recursion
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        
        // mark current cell as visited
        grid[row][col] = '2';
        
        // recursive calls 
        dfs(grid, row - 1, col); 
        dfs(grid, row + 1, col); 
        dfs(grid, row, col - 1); 
        dfs(grid, row, col + 1); 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        
        // check each cell in the grid
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    islandCount++;
                    dfs(grid, row, col);
                }
            }
        }
        
        return islandCount;
    }
};

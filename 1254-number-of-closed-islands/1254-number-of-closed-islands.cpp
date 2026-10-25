class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If the cell is out of bounds, then this component touches the edge (not closed).
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's bounded/valid for this path.
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark the current land cell as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Visit all 4 neighboring directions
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        
        // A closed island requires all directions to be valid (not touching the boundary)
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslandsCount = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we find an unvisited land cell (0), run DFS
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};
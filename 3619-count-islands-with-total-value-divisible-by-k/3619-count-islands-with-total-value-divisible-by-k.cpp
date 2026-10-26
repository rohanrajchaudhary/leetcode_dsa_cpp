class Solution {
private:
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long sum = grid[r][c];
        grid[r][c] = 0; // Mark as visited
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                sum += dfs(grid, nr, nc);
            }
        }
        
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long totalValue = dfs(grid, i, j);
                    if (totalValue % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
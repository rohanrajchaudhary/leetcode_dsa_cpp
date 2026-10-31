class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        // dp[i][j][0]: ways entering (i, j) moving DOWN (from above)
        // dp[i][j][1]: ways entering (i, j) moving RIGHT (from left)
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
        
        // Base cases from start (0, 0)
        if (grid[0][0] == 0) {
            if (m > 1) dp[1][0][0] = 1; // move down to (1, 0)
            if (n > 1) dp[0][1][1] = 1; // move right to (0, 1)
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If current cell is a mirror (1), it deflects incoming paths:
                // - Incoming from above (moving down) hits mirror (i, j) -> turns RIGHT to (i, j+1)
                // - Incoming from left (moving right) hits mirror (i, j) -> turns DOWN to (i+1, j)
                if (grid[i][j] == 1) {
                    long long from_above = dp[i][j][0];
                    long long from_left = dp[i][j][1];
                    
                    if (j + 1 < n) {
                        dp[i][j+1][1] = (dp[i][j+1][1] + from_above) % MOD;
                    }
                    if (i + 1 < m) {
                        dp[i+1][j][0] = (dp[i+1][j][0] + from_left) % MOD;
                    }
                } 
                // If current cell is empty (0), paths pass straight through:
                else {
                    long long total_in = (dp[i][j][0] + dp[i][j][1]) % MOD;
                    if (total_in > 0) {
                        if (i + 1 < m) {
                            dp[i+1][j][0] = (dp[i+1][j][0] + total_in) % MOD;
                        }
                        if (j + 1 < n) {
                            dp[i][j+1][1] = (dp[i][j+1][1] + total_in) % MOD;
                        }
                    }
                }
            }
        }
        
        // We need paths reaching the bottom-right corner (m-1, n-1)
        long long ans = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
        return ans;
    }
};
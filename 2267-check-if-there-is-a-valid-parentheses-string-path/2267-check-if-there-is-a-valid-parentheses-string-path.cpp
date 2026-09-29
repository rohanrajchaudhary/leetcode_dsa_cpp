class Solution {
    int m, n;
    bool memo[100][100][105];

    bool dfs(int r, int c, int k, const vector<vector<char>>& grid) {
        // Balance delta for current cell
        k += (grid[r][c] == '(' ? 1 : -1);

        // Invalid if balance drops below 0
        if (k < 0) return false;

        // Balance cannot exceed remaining steps needed to close all '('
        int remainingSteps = (m - 1 - r) + (n - 1 - c);
        if (k > remainingSteps) return false;

        // Base case: reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return k == 0;
        }

        // Memoization check
        if (memo[r][c][k]) return false;
        memo[r][c][k] = true;

        // Explore down and right
        if (r + 1 < m && dfs(r + 1, c, k, grid)) return true;
        if (c + 1 < n && dfs(r, c + 1, k, grid)) return true;

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length is m + n - 1; must be even to be valid
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Initialize memo array to false
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2 + 1; ++k) {
                    memo[i][j][k] = false;
                }
            }
        }

        return dfs(0, 0, 0, grid);
    }
};
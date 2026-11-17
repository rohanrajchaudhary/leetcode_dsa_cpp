class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        for (int j = 0; j < len / d / 2; j++) {
                            int a = l + i + j * d;
                            int b = l + i + (len / d - 1 - j) * d;

                            if (s[a] != s[b]) {
                                changes++;
                            }
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (i - j >= 2 && dp[parts - 1][j] != 1e9) {
                        dp[parts][i] = min(
                            dp[parts][i],
                            dp[parts - 1][j] + cost[j][i - 1]
                        );
                    }
                }
            }
        }

        return dp[k][n];
    }
};
class Solution {
private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long left_ways = dfs(left) % mod;
        long long right_ways = dfs(right) % mod;

        int left_size = left.size();
        int right_size = right.size();

        return (((table[m - 1][left_size] * left_ways) % mod) * right_ways) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }

        return (dfs(nums) - 1 + mod) % mod;
    }
};
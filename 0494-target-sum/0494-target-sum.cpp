class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        if(abs(target) > sum)
        return 0;
        vector<vector<int>> dp(n+1,vector<int> (2*sum+1, 0));
        dp[0][sum] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= 2*sum; j++)
            {
                if(dp[i-1][j] > 0)
                {
                    int plus = j+nums[i-1];
                    int minus = j-nums[i-1];
                    dp[i][plus] += dp[i-1][j];
                    dp[i][minus] += dp[i-1][j];
                }
            }
        }
        return dp[n][target+sum];
    }
};
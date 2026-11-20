class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(nums[n - 1] + 2, 0);
        int answer = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);

            answer = max(answer, dp[x + 1]);
            answer = max(answer, dp[x]);
        }

        return answer;
    }
};
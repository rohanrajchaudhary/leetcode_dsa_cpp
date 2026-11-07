class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        if(start == end)
        return nums[start];
        vector<int> dp(end-start+1,0);
        dp[0] = nums[start];
        dp[1] = max(nums[start],nums[start+1]);
        for(int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i-2] + nums[start+i], dp[i-1]);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return nums[0];
        int case1 = robRange(nums,0,n-2);
        int case2 = robRange(nums,1,n-1);
        return max(case1,case2);
    }
};
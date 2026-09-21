class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        // dp[r] represents the count of subarrays ending at the previous element with product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int val = num % k;
            
            // Subarray starting at the current element
            next_dp[val]++;

            // Extend existing subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (1LL * r * val) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Accumulate to overall results
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return result;
    }
};
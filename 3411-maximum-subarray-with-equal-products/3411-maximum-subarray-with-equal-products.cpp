class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int gcdValue = 0;
            int lcmValue = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];
                if (product > 25200) break; 
                gcdValue = std::gcd(gcdValue, nums[j]);
                lcmValue = std::lcm(lcmValue, nums[j]);

                if (product == 1LL * gcdValue * lcmValue) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
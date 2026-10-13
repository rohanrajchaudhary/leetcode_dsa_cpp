class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        
        long long score = 0;
        int negCount = n / 2;
        
        for (int i = 0; i < negCount; ++i) {
            long long val = nums[i];
            score -= val * val;
        }
        
        for (int i = negCount; i < n; ++i) {
            long long val = nums[i];
            score += val * val;
        }
        
        return score;
    }
};
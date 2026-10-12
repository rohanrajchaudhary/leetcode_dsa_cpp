class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31, 0);
        
        // Step 1: Count the set bits at each position
        for (int num : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        // Step 2: Greedily construct the k largest numbers
        for (int i = 0; i < k; ++i) {
            long long currentNum = 0;
            for (int bit = 0; bit <= 30; ++bit) {
                if (bitCount[bit] > 0) {
                    currentNum |= (1LL << bit);
                    bitCount[bit]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSum;
    }
};
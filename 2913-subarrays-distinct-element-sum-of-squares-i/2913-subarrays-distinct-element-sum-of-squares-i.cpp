class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        
        
        // Generate all possible subarrays
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> distinctElements;
            for (int j = i; j < nums.size(); j++) {
                distinctElements.insert(nums[j]);
                int count = distinctElements.size();
                totalSum = totalSum + count * count;
            }
        }
        
        return totalSum;
    }
};
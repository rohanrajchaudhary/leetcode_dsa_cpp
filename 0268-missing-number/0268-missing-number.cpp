class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int actualSum = 0;
        int n = nums.size();
        sum = n*(n+1)/2;
        for(int i = 0; i < nums.size(); i++)
        {
            actualSum = actualSum + nums[i];
        }
        return sum - actualSum;
    }
};
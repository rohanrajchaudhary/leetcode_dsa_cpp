class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum = sum + nums[i];
        }
        int maxSum = sum;
        for(int right = k; right < nums.size(); right++)
        {
            sum = sum + nums[right];
            sum = sum - nums[right - k];
        
        if(sum > maxSum)
        {
            maxSum = sum;
        }
        }
        return (double)maxSum/k;
    }
};
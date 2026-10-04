class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int oldMax = currentMax;
            int oldMin = currentMin;

            currentMax = max(max(nums[i], oldMax*nums[i]), oldMin*nums[i]);
             currentMin = min(min(nums[i], oldMax*nums[i]), oldMin*nums[i]);
             if (currentMax > answer)
             {
                answer = currentMax;
             }
        }
        return answer;
           
    }
};  

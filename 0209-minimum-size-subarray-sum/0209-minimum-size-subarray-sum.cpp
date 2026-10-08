class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = nums.size() + 1;
        for(int right = 0; right < nums.size(); right++)
        {
            sum = sum + nums[right];
            while(sum >= target)
            {
                int currentLength = right - left + 1;
                if(currentLength < minLength)
                {
                    minLength = currentLength;
                }
                sum = sum - nums[left];
                left++;
            }
            

        }
         if(minLength == nums.size() +1)
            {
                return 0;
            }
        return minLength;
    }
};
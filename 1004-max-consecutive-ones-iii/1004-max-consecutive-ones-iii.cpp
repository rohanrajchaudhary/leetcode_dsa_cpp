class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int zeroCount = 0;
       int left = 0;
       int maxLength = 0;
       for(int right = 0; right < nums.size(); right++)
       {
        if(nums[right] == 0)
        {
         zeroCount++;
        }
       
        while(zeroCount > k)
        {
            if(nums[left] == 0){
            zeroCount--;
        }
        left++;
        }
        int currentLength = right - left + 1;
        if(currentLength > maxLength)
        {
            maxLength = currentLength;
        }
       }
       return maxLength;
    }
};
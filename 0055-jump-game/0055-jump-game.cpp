class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i <= farthest)
            {
                farthest = max(farthest,nums[i] + i);
            }
        }
        return farthest >= nums.size() - 1;
    }
};
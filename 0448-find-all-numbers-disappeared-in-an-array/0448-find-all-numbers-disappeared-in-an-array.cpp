class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missValue;

        for(int i = 0; i < nums.size(); i++)
        {
            int num = abs(nums[i]);

            if(nums[num - 1] > 0)
            {
                nums[num - 1] = -nums[num - 1];
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                missValue.push_back(i + 1);
            }
        }

        return missValue;
    }
};
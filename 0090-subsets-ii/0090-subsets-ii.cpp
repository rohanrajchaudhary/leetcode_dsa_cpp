class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& answer)
    {
        answer.push_back(current);
        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i-1])
            {
                continue;
            }
            current.push_back(nums[i]);
            solve(nums, i+1, current, answer);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        vector<int> current;
        solve(nums,0,current,answer);
        return answer;
    }
};
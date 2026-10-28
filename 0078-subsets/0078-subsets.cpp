class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& answer)
    {
        if(index == nums.size())
        {
            answer.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solve(nums,index+1,current,answer);
        current.pop_back(); //backtracking
        solve(nums,index+1,current,answer);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> empty;
        solve(nums,0,empty,answer);
        return answer;
    }
};
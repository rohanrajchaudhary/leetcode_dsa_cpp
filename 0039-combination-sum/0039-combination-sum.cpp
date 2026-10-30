class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<int>& current, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(current);
            return;
        }
        if(target < 0)
        {
            return;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            solve(candidates,i,target - candidates[i],current,ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>> ans;
     vector<int> current;
     solve(candidates,0,target,current,ans);
     return ans;   
    }
};
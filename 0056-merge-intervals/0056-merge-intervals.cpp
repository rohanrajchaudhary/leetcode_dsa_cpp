class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        // vector<vector<int>> ans;
        vector<vector<int>> ans;
        for(int i = 0; i < interval.size(); i++)
        {
            if(ans.empty()||ans.back()[1] < interval[i][0])
            {
                ans.push_back(interval[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],interval[i][1]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string Prefix = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            for(int j = 0; j < Prefix.size(); j++)
            {
                if(j >= strs[i].size() || Prefix[j] != strs[i][j])
                {
                    Prefix = Prefix.substr(0,j);
                    break;
                }
            }
        }
        return Prefix;
    }
};
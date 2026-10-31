class Solution {
public:
    bool isPalindrome(string& part)
    {
        int left = 0;
        int right = part.size() - 1;
        while(left < right)
        {
            if(part[left] != part[right])
            {
                return false;

            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string& s, int index, vector<string>& current, vector<vector<string>>& ans)
    {
        if(index == s.size())
        {
            ans.push_back(current);
            return;
        }
        for(int i = index; i < s.size(); i++)
        {
            string part = s.substr(index, i-index + 1);
            if(isPalindrome(part))
            {
                current.push_back(part);
                solve(s,i+1,current,ans);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        solve(s,0,current,ans);
        return ans;
    }
};
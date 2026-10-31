class Solution {
public:
    void solve(string& digits, int index, string& current, vector<string>& ans)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string keypad[] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        int digit = digits[index] - '0';
        string letters = keypad[digit];
        for(int i = 0; i < letters.size(); i++)
        {
            current.push_back(letters[i]);
            solve(digits, index+1, current, ans);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string current;
        if(digits.empty())
        {
            return ans;
        }
        solve(digits,0,current,ans);
        return ans;
    }
};
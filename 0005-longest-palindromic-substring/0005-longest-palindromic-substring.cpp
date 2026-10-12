class Solution {

public:

    string longestPalindrome(string s) {

        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            int start = left + 1;
            int end = right - 1;

            int length = end - start + 1;

            if(length > ans.size())
            {
                ans = s.substr(start, length);
            }

            left = i;
            right = i + 1;

            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }

            start = left + 1;
            end = right - 1;

            length = end - start + 1;

            if(length > ans.size())
            {
                ans = s.substr(start, length);
            }
        }

        return ans;
    }
};
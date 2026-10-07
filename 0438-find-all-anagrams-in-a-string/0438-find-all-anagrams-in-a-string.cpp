class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(p.size() > s.size())
        {
            return {};
        }

        int countP[26] = {0};
        int countS[26] = {0};

        for(int i = 0; i < p.size(); i++)
        {
            countP[p[i] - 'a']++;
        }

        for(int i = 0; i < p.size(); i++)
        {
            countS[s[i] - 'a']++;
        }

        vector<int> ans;

        bool same = true;

        for(int i = 0; i < 26; i++)
        {
            if(countP[i] != countS[i])
            {
                same = false;
                break;
            }
        }

        if(same)
        {
            ans.push_back(0);
        }

        int left = 0;

        for(int right = p.size(); right < s.size(); right++)
        {
            countS[s[right] - 'a']++;
            countS[s[left] - 'a']--;
            left++;

            same = true;

            for(int i = 0; i < 26; i++)
            {
                if(countP[i] != countS[i])
                {
                    same = false;
                    break;
                }
            }

            if(same)
            {
                ans.push_back(right - p.size() + 1);
            }
        }

        return ans;
    }
};
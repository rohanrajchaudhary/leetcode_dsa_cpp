class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        unordered_map<char,char> mp;
        unordered_map<char,char> revMp;
        for(int i = 0; i<s.size(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])
                {
                    return false;
                }
            }
            if(revMp.find(t[i]) != revMp.end())
            {
                if(revMp[t[i]] != s[i])
                {
                    return false;
                }
            }
            mp[s[i]] = t[i];
            revMp[t[i]] = s[i];
        }
        return true;
    }
};
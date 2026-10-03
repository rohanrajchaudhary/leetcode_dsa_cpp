class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        unordered_map<char,string> mp;
        unordered_map<string,char> revMp;
        int i = 0;
        while(ss >> word)
        {
            if(i >= pattern.size())
            {
                return false;
            }
            if(mp.find(pattern[i]) != mp.end())
            {
                if(mp[pattern[i]] != word)
                {
                    return false;
                }
            }
            if(revMp.find(word) != revMp.end())
            {
                if(revMp[word] != pattern[i])
                {
                    return false;
                }
            }
            mp[pattern[i]] = word;
            revMp[word] = pattern[i];
            i++;
        }
        if(i != pattern.size())
        {
            return false;
        }
        return true;
    }
};
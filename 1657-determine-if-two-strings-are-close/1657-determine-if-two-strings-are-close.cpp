class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int count1[26] = {0};
        int count2[26] = {0};
        int freq1[100001] = {0};
        int freq2[100001] = {0};
        for(int i = 0; i < word1.size(); i++)
        {
            count1[word1[i] - 'a']++;
        }
        for(int i = 0; i < word2.size(); i++)
        {
            count2[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0))
            {
                return false;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(count1[i] > 0)
            {
                freq1[count1[i]]++;
            }

        }
        for(int i = 0; i < 26; i++)
        {
            if(count2[i] > 0)
            {
                freq2[count2[i]]++;
            }
        }
        for(int i = 0; i < 100001; i++)
        {
            if(freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }
};
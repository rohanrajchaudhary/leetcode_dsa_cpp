class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        if(s1.size() > s2.size())
        {
            return false;
        }

        int count1[26] = {0};
        int count2[26] = {0};

        for(int i = 0; i < s1.size(); i++)
        {
            count1[s1[i] - 'a']++;
        }

        for(int i = 0; i < s1.size(); i++)
        {
            count2[s2[i] - 'a']++;
        }

        bool same = true;

        for(int i = 0; i < 26; i++)
        {
            if(count1[i] != count2[i])
            {
                same = false;
                break;
            }
        }

        if(same)
        {
            return true;
        }

        int left = 0;

        for(int right = s1.size(); right < s2.size(); right++)
        {
            count2[s2[right] - 'a']++;
            count2[s2[left] - 'a']--;
            left++;

            same = true;

            for(int i = 0; i < 26; i++)
            {
                if(count1[i] != count2[i])
                {
                    same = false;
                    break;
                }
            }

            if(same)
            {
                return true;
            }
        }

        return false;
    }
};
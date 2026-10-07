class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] -'A']);
            while((right - left + 1 - maxFreq) > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            int currentLength = right - left + 1;
            if(currentLength > maxLength)
            {
                maxLength = currentLength;
            }

        }
        return maxLength;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
    //    int mp = 0;
        int left = 0;
        int maxLength = 0;
        for(int right= 0; right < fruits.size(); right++)
        {
            mp[fruits[right]]++;
        
            while(mp.size() > 2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                            left++;

            }
            // left++;

        
        int currentLength = right - left + 1;
        if(currentLength > maxLength)
        {
        maxLength = currentLength;
        }
        }
        return maxLength;
    }
};
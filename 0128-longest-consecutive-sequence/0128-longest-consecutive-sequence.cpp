class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int longest = 0;

        for(int x : s) {
            
            if(s.find(x - 1) == s.end()) {
                
                int len = 1;
                int current = x;

                while(s.find(current + 1) != s.end()) {
                    current++;
                    len++;
                }

                if(len > longest) {
                    longest = len;
                }
            }
        }

        return longest;
    }
};
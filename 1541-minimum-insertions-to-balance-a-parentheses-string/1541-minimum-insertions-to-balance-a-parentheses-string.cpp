class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int need = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
            
                if (need % 2 != 0) {
                    res++;
                    need--; // One ')' need is satisfied by insertion, leaving even requirement
                }
                need += 2; // Each '(' requires two ')' characters
            } else {
                need--; 
                if (need < 0) {
                    res++;     
                    need += 2; 
                }
            }
        }
        
        return res + need;
    }
};
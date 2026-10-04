class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0; // Minimum possible open brackets
        int cmax = 0; // Maximum possible open brackets

        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; // Treat '*' as ')'
                cmax++; // Treat '*' as '('
            }

            // More ')' than '(' + '*' seen so far
            if (cmax < 0) return false;

            // cmin can never be negative; excess can be treated as empty string ""
            cmin = max(cmin, 0);
        }

        return cmin == 0;
    }
};
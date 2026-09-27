class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair(n);
        vector<int> openStack;

        // Step 1: Matching brackets ke indices map karo
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openStack.push_back(i);
            } else if (s[i] == ')') {
                int j = openStack.back();
                openStack.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Step 2: Jump/wormhole traversal (O(n))
        string res = "";
        int dir = 1;

        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};
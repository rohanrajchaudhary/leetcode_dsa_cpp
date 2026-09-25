class Solution {
    int idx = 0;
    string s;

    // Expr -> Term (',' Term)*
    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (idx < s.size() && s[idx] == ',') {
            idx++; // ',' skip karo
            set<string> nextTerm = parseTerm();
            result.insert(nextTerm.begin(), nextTerm.end());
        }
        return result;
    }

    // Term -> Factor+ (Cartesian product / Concatenation)
    set<string> parseTerm() {
        set<string> result = {""};
        while (idx < s.size() && (isalpha(s[idx]) || s[idx] == '{')) {
            set<string> factor = parseFactor();
            set<string> combined;
            for (const string& prefix : result) {
                for (const string& suffix : factor) {
                    combined.insert(prefix + suffix);
                }
            }
            result = move(combined);
        }
        return result;
    }

    // Factor -> letter | '{' Expr '}'
    set<string> parseFactor() {
        if (s[idx] == '{') {
            idx++; // '{' skip karo
            set<string> res = parseExpr();
            idx++; // '}' skip karo
            return res;
        } else {
            string letter(1, s[idx++]);
            return {letter};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        idx = 0;
        set<string> finalSet = parseExpr();
        return vector<string>(finalSet.begin(), finalSet.end());
    }
};
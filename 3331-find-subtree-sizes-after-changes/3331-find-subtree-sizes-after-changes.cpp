class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);

        for (int node = 1; node < n; node++) {
            children[parent[node]].push_back(node);
        }

        vector<int> closest(26, -1);
        vector<int> previous(n);
        vector<int> newParent = parent;
        vector<int> answer(n, 1);

      
        stack<pair<int, bool>> events;
        events.push({0, false});

        while (!events.empty()) {
            auto [node, leaving] = events.top();
            events.pop();

            int letter = s[node] - 'a';

            if (leaving) {
                closest[letter] = previous[node];

                if (node != 0) {
                    answer[newParent[node]] += answer[node];
                }
                continue;
            }

            previous[node] = closest[letter];

            if (closest[letter] != -1) {
                newParent[node] = closest[letter];
            }

            closest[letter] = node;
            events.push({node, true});

            for (int child : children[node]) {
                events.push({child, false});
            }
        }

        return answer;
    }
};
class Solution {
    struct State {
        int length = 0;
        int link = -1;
        int occurrences = 0;
        unordered_map<int, int> next;
    };

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<State> states;
        states.reserve(2 * n);
        states.emplace_back();

        int last = 0;

        for (int i = 0; i < n; i++) {
            int value = nums[i];
            int current = states.size();
            states.emplace_back();
            states[current].length = states[last].length + 1;
            states[current].occurrences = 1;

            int p = last;
            while (p != -1 && !states[p].next.count(value)) {
                states[p].next[value] = current;
                p = states[p].link;
            }

            if (p == -1) {
                states[current].link = 0;
            } else {
                int q = states[p].next.at(value);

                if (states[p].length + 1 == states[q].length) {
                    states[current].link = q;
                } else {
                    int clone = states.size();
                    states.push_back(states[q]);
                    states[clone].length = states[p].length + 1;
                    states[clone].occurrences = 0;

                    while (p != -1) {
                        auto it = states[p].next.find(value);
                        if (it == states[p].next.end() || it->second != q) {
                            break;
                        }
                        it->second = clone;
                        p = states[p].link;
                    }

                    states[q].link = clone;
                    states[current].link = clone;
                }
            }

            last = current;
        }

        int size = states.size();
        vector<int> count(n + 1, 0);
        vector<int> order(size);

        for (int i = 0; i < size; i++) {
            count[states[i].length]++;
        }

        for (int i = 1; i <= n; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            order[--count[states[i].length]] = i;
        }

        int answer = n;

        for (int i = size - 1; i > 0; i--) {
            int state = order[i];
            int parent = states[state].link;

            if (states[state].occurrences == 1) {
                answer = min(answer, states[parent].length + 1);
            }

            states[parent].occurrences += states[state].occurrences;
        }

        return answer;
    }
};
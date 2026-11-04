class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();
            return median * left.size() - sumL
                 + sumR - median * right.size();
        };

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                                  prev[i - x] + cost[i - x]);
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
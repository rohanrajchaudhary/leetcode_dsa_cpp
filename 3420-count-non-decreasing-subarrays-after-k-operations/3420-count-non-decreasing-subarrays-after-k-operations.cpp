
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 18;

        vector<int> nge(n + 1, n), st;
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];

            while (!st.empty() && nums[st.back()] <= nums[i]) {
                nge[st.back()] = i;
                st.pop_back();
            }

            st.push_back(i);
        }

        vector<vector<int>> jump(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            jump[0][i] = nge[i];
            sum[0][i] = 1LL * nums[i] * (nge[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = jump[j - 1][i];

                jump[j][i] = jump[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        auto getCost = [&](int l, int r) -> long long {
            long long total = 0;
            int p = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (jump[j][p] <= r) {
                    total += sum[j][p];
                    p = jump[j][p];
                }
            }

            total += 1LL * nums[p] * (r - p + 1);

            return total - (pref[r + 1] - pref[l]);
        };

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            int low = l, high = n - 1;
            int best = l - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (getCost(l, mid) <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            ans += best - l + 1;
        }

        return ans;
    }
};
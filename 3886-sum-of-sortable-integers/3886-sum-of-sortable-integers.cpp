class Solution {
private:
    bool isCyclicRotation(const vector<int>& block, const vector<int>& target) {
        int k = block.size();
        if (block == target) return true;
        
        vector<int> text = block;
        text.insert(text.end(), block.begin(), block.end());
        
        vector<int> lps(k, 0);
        int len = 0;
        int i = 1;
        while (i < k) {
            if (target[i] == target[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        i = 0;
        int j = 0;
        while (i < 2 * k) {
            if (target[j] == text[i]) {
                i++;
                j++;
            }
            if (j == k) {
                return true;
            } else if (i < 2 * k && target[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int totalSum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool possible = true;
            for (int i = 0; i < n; i += k) {
                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                vector<int> target(sorted_nums.begin() + i, sorted_nums.begin() + i + k);

                if (!isCyclicRotation(block, target)) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                totalSum += k;
            }
        }

        return totalSum;
    }
};
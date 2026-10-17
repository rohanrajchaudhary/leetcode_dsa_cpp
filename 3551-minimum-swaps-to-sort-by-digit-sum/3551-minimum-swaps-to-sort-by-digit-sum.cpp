class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        auto getDigitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        
        vector<tuple<int, int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        
        sort(items.begin(), items.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || get<2>(items[i]) == i) {
                continue;
            }
            
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = get<2>(items[curr]);
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};
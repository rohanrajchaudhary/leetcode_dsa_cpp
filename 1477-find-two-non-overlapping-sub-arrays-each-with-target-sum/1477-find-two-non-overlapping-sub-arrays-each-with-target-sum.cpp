class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        
        int current_sum = 0;
        int ans = INT_MAX;
        int shortest_so_far = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            
            int needed = current_sum - target;
            if (prefix_map.count(needed)) {
                int start_idx = prefix_map[needed];
                int current_length = i - start_idx;
                
                if (start_idx >= 0 && min_len[start_idx] != INT_MAX) {
                    ans = min(ans, current_length + min_len[start_idx]);
                }
                
                shortest_so_far = min(shortest_so_far, current_length);
            }
            
            min_len[i] = shortest_so_far;
            prefix_map[current_sum] = i;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
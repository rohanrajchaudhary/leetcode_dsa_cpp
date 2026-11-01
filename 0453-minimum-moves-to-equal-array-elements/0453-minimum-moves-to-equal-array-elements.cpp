class Solution {
public:
int minMoves(vector<int>& nums) {
    // Step 1: Find the minimum element in the array
    int min_val = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
    }
    
    // Step 2: Calculate the total moves
    int moves = 0;
    for (int i = 0; i < n; i++) {
        moves = moves + (nums[i] - min_val);
    }
    
    return moves;
}
};
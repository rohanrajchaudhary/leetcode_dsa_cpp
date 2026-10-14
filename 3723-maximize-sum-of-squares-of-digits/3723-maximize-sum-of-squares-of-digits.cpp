class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        
        string result = "";
        
        // Greedily add '9's
        while (sum >= 9 && result.length() < num - 1) {
            result += '9';
            sum -= 9;
        }
        
        // If we only have one slot left or need to place the remainder
        if (result.length() < num) {
            result += to_string(sum);
            sum = 0;
        }
        
        // Pad the rest with '0's to match the required number of digits 'num'
        while (result.length() < num) {
            result += '0';
        }
        
        // If there's still leftover sum that couldn't fit because of length constraints
        if (sum > 0 || result.length() != num) {
            return "";
        }
        
        return result;
    }
};
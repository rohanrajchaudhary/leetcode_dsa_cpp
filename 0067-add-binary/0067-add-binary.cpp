class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry != 0) {
            int bit1 = 0;
            int bit2 = 0;

            if(i >= 0) bit1 = a[i] - '0';
            if(j >= 0) bit2 = b[j] - '0';

            int sum = bit1 + bit2 + carry;

            ans += to_string(sum % 2);
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
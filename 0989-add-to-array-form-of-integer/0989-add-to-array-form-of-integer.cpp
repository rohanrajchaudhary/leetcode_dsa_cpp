class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int i = num.size() - 1;
        int carry = 0;

        while(i >= 0 || k > 0 || carry > 0)
        {
            int digit = 0;

            if(k > 0)
            {
                digit = k % 10;
            }

            int current = 0;

            if(i >= 0)
            {
                current = num[i];
            }

            int sum = current + digit + carry;

            if(i >= 0)
            {
                num[i] = sum % 10;
            }
            else
            {
                num.insert(num.begin(), sum % 10);
            }

            carry = sum / 10;

            k = k / 10;
            i--;
        }

        return num;
    }
};
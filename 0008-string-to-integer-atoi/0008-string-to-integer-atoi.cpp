class Solution {

public:

    int myAtoi(string s) {

        int i = 0;
        int sign = 1;

        while(i < s.size() && s[i] == ' ')
        {
            i++;
        }

        if(i < s.size() && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(i < s.size() && s[i] == '+')
        {
            sign = 1;
            i++;
        }

        long long ans = 0;

        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            if(sign == 1)
            {
                if(ans > 214748364 ||
                   (ans == 214748364 && s[i] - '0' > 7))
                {
                    return 2147483647;
                }
            }
            else
            {
                if(ans > 214748364 ||
                   (ans == 214748364 && s[i] - '0' > 8))
                {
                    return -2147483647 - 1;
                }
            }

            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return sign * ans;
    }
};
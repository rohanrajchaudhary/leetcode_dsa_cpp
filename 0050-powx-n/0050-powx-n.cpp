class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        long double base = (long double)x;

        if(power < 0) {
            power = -power;
        }

        long double ans = 1.0L;

        while(power > 0) {
            if(power % 2 == 1) {
                ans *= base;
            }

            base *= base;
            power /= 2;
        }

        if(n < 0) {
            ans = 1.0L / ans;
        }

        return (double)ans;
    }
};
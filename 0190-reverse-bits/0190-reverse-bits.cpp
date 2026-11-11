class Solution {
public:
    int reverseBits(int n) {
        uint32_t rev = 0;
        for(int i = 0; i < 32; i++)
        {
            rev = rev << 1;
            rev = rev | (n & 1);
            n = n >> 1;
        }
        return rev;
    }
};
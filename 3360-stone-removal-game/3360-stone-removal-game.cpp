class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceTurn = true;

        for (int stones = 10; stones > n || stones > 0; stones--) {
            if (n < stones) {
                return !aliceTurn;
            }

            n = n - stones;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};
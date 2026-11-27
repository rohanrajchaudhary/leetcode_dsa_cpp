class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> best(budget + 1, 0);
        vector<int> take(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];
            int firstPurchase = 1;

            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % factor == 0) {
                    firstPurchase++;
                }
            }

            for (int money = price; money <= budget; money++) {
                take[money] = best[money - price] + firstPurchase;

                if (money >= 2 * price) {
                    take[money] = max(take[money], take[money - price] + 1);
                }
            }

            for (int money = price; money <= budget; money++) {
                best[money] = max(best[money], take[money]);
            }
        }

        return best[budget];
    }
};
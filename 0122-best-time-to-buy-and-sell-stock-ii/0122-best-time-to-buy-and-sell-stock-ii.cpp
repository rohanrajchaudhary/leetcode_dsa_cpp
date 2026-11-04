class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int tom_amt = 0;
        int tod_amt = 0;
        for(int i = 0; i < prices.size() -1; i++)
        {
            tod_amt = prices[i];
            tom_amt = prices[i+1];
            if(tom_amt > tod_amt)
            {
                profit = profit + (tom_amt - tod_amt);
            }
        }
        return profit;
    }
};
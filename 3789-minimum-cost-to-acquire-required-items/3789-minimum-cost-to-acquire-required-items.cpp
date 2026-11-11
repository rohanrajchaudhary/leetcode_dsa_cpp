class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long a = min(1LL * costBoth, 1LL * cost1+cost2);
       long long both = min(need1, need2);
       long long ans = both * a;
       ans = ans + 1LL * (need1 - both) * min(cost1, costBoth);
       ans = ans + 1LL * (need2 - both) * min(cost2, costBoth);
       return ans; 
    }
};
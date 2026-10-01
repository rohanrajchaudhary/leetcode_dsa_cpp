class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL*m*k;
        if(totalFlowers > bloomDay.size())
        {
            return -1;
        }
        int low = bloomDay[0];
        int high = bloomDay[0];
        for(int i = 1; i < bloomDay.size(); i++)
        {
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        while(low < high)
        {
            int mid = low+(high-low)/2;
            int flowers = 0;
            int bouquets = 0;
            for(int i = 0; i < bloomDay.size();i++)
            {
                if(bloomDay[i] <= mid)
                {
                    flowers++;
                    if(flowers == k)
                    {
                        bouquets++;
                        flowers = 0;
                    }
                }
                else
                {
                    flowers = 0;
                }
            }
            if (bouquets >= m)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};
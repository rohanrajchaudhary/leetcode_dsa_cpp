class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long totalK = (long long)k1 + k2;
        long long sumDiff = 0;
        
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sumDiff += diff[i];
        }
        
        
        if (sumDiff <= totalK) return 0;
        
    
        long long low = 0, high = *max_element(diff.begin(), diff.end());
        long long targetMaxDiff = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long operationsNeeded = 0;
            for (int i = 0; i < n; ++i) {
                if (diff[i] > mid) {
                    operationsNeeded += (diff[i] - mid);
                }
            }
            
            if (operationsNeeded <= totalK) {
                targetMaxDiff = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
       
        long long opsUsed = 0;
        for (int i = 0; i < n; ++i) {
            if (diff[i] > targetMaxDiff) {
                opsUsed += (diff[i] - targetMaxDiff);
                diff[i] = targetMaxDiff;
            }
        }
        
      
        long long remainderOps = totalK - opsUsed;
        for (int i = 0; i < n && remainderOps > 0; ++i) {
            if (diff[i] == targetMaxDiff && diff[i] > 0) {
                diff[i]--;
                remainderOps--;
            }
        }
   
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += diff[i] * diff[i];
        }
        
        return ans;
    }
};
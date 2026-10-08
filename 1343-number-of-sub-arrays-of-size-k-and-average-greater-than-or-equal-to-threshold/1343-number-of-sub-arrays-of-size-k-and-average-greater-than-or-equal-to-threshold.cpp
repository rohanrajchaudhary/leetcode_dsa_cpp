class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int target = k * threshold;
        for(int i = 0; i < k; i++)
        {
            sum = sum + arr[i];

        }
        int count = 0;
        if(sum >= target)
        {
            count++;
        }
        for(int right = k; right < arr.size(); right++)
        {
            sum = sum + arr[right];
            sum = sum - arr[right - k];
              if(sum >= target)
        {
            count++;
        }
        }
       
        return count;
    }
};
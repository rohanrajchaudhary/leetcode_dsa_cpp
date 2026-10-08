class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for(int i = 0; i < k; i++)
        {
            if(blocks[i] == 'W')
            {
                count++;
            }
        }    
            int minCount = count;
            for(int right = k; right < blocks.size(); right++)
            {
                if(blocks[right] == 'W')
                {
                    count++;
                }
                if(blocks[right-k] == 'W')
                {
                    count--;
                }
                if(count < minCount)
                {
                    minCount = count;
                }
            }
            return minCount;
        
    }
};
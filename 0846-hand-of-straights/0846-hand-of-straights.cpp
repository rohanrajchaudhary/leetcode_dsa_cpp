class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
         return false;
         sort(hand.begin(), hand.end());
         unordered_map<int,int> freq;
         for(int i = 0; i < hand.size(); i++)
         {
            freq[hand[i]]++;
         }
         for(int i = 0; i < hand.size(); i++)
         {
           int x = hand[i];
           if(freq[x] > 0)
           {
            for(int j = 0; j < groupSize; j++)
            {
                if(freq[x+j] <= 0)
                return false;
                freq[x+j]--;
            }
           }
         }
         return true;
    }
};
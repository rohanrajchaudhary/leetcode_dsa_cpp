class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int start = 0;
        int petrol = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            total = total + gas[i] - cost[i];
            petrol = petrol + gas[i] - cost[i];
            if(petrol < 0)
            {
                start = i + 1;
                petrol = 0;
            }
        }
        if(total < 0)
        {
            return -1;
        }
        return start;
    }
};
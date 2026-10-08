class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;

for(int i = 0; i < customers.size(); i++)
{
    if(grumpy[i] == 0)
    {
        base = base + customers[i];
    }
}

int extra = 0;

for(int i = 0; i < minutes; i++)
{
    if(grumpy[i] == 1)
    {
        extra = extra + customers[i];
    }
}

int maxExtra = extra;

for(int right = minutes; right < customers.size(); right++)
{
    if(grumpy[right] == 1)
    {
        extra = extra + customers[right];
    }

    if(grumpy[right - minutes] == 1)
    {
        extra = extra - customers[right - minutes];
    }

    if(extra > maxExtra)
    {
        maxExtra = extra;
    }
}

return base + maxExtra;
    }
};
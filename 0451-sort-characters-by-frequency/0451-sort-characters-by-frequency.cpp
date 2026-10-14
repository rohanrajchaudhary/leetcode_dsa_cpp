class Solution {
public:
    static bool compare(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        vector<int> count(256, 0);

        for(int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
        }

        vector<pair<char, int>> arr;

        for(int i = 0; i < 256; i++)
        {
            if(count[i] > 0)
            {
                arr.push_back({char(i), count[i]});
            }
        }

        sort(arr.begin(), arr.end(), compare);

        string ans = "";
        ans.reserve(s.size());

        for(int i = 0; i < arr.size(); i++)
        {
            while(arr[i].second > 0)
            {
                ans += arr[i].first;
                arr[i].second--;
            }
        }

        return ans;
    }
};
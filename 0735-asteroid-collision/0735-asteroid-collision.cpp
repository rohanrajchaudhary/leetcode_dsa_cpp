class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i = 0; i < asteroids.size(); i++)
        {
            bool destroyed = false;
            while(!ans.empty() && ans.back() > 0 && asteroids[i] < 0 && ans.back() < -asteroids[i])
            {
                ans.pop_back();
            }
            if(!ans.empty() && asteroids[i] < 0 && ans.back() > 0 && ans.back() == -asteroids[i])
            {
                ans.pop_back();
                destroyed = true;
            }
            else if(!ans.empty() && asteroids[i] < 0 && ans.back() > 0 && ans.back() > -asteroids[i])
            {
                destroyed = true;
            }
            if(!destroyed)
            {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};
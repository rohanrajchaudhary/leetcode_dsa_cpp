class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                int heightIndex = st.top();
                st.pop();

                int width;

                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }

                int area = heights[heightIndex] * width;
                ans = max(ans, area);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int heightIndex = st.top();
            st.pop();

            int width;

            if(st.empty())
            {
                width = heights.size();
            }
            else
            {
                width = heights.size() - st.top() - 1;
            }

            int area = heights[heightIndex] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};
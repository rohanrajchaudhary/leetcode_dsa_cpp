class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        map<int,int> greater;
        for(int i = 0; i < nums2.size(); i++)
        {
            while(!st.empty() && nums2[i] > st.top())
            {
                greater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty())
        {
            greater[st.top()] = -1;
            st.pop();
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(greater[nums1[i]]);
        }
        return ans;
    }
};
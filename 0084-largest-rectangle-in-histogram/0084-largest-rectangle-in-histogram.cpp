class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int maxArea = INT_MIN;
        int n = heights.size();
        for(int i = 0; i < n; i++)
        {
            int itr = i;
            while(!st.empty() && st.top().second > heights[i])
            {
                int idx = st.top().first;
                int height = st.top().second;
                st.pop();
                maxArea = max(maxArea, (i - idx) * height);
                itr = idx;
            }
            st.push({itr,heights[i]});
        }  

        while(!st.empty())
        {
            int idx = st.top().first;
            int height = st.top().second;
            st.pop();
            maxArea = max(maxArea, (n - idx) * height);
        }
        return maxArea;
    }
};
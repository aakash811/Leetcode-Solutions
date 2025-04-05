class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>stk;
        int maxArea = INT_MIN;

        for(int i = 0; i < n; i++){
            int itr = i;
            while(!stk.empty() && stk.top().second > heights[i]){
                int idx = stk.top().first;
                int hgt = stk.top().second;
                stk.pop();

                maxArea = max(maxArea, (i - idx) * hgt);
                itr = idx;
            }
            stk.push({itr, heights[i]});
        }

        while(!stk.empty()){
           int idx = stk.top().first;
           int hgt = stk.top().second;
           stk.pop();
           maxArea = max(maxArea, (n - idx) * hgt);
        }
        return maxArea;
    }
};
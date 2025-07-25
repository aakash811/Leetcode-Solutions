class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>>stk;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int iterator = i;
            while(!stk.empty() && stk.top().second > heights[i]){
                int idx = stk.top().first;
                int hgt = stk.top().second;
                stk.pop();
                maxArea = max(maxArea, (i - idx) * hgt);
                iterator = idx;
            }
            stk.push({iterator, heights[i]});
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
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxArea = INT_MIN;

        while(i < j){
            int minHgt = min(height[i], height[j]);
            int area = (j - i) * minHgt;
            
            maxArea = max(maxArea, area);

            if(minHgt == height[i]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxArea;
    }
};
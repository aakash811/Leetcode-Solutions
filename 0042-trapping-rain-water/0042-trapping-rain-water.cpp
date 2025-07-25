class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int i = 0;
        int j = n - 1;
        int vol = 0;

        while(i < j){
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);

            if(leftMax < rightMax){
                vol += leftMax - height[i];
                i++;
            }
            else{
                vol += rightMax - height[j];
                j--;
            }
        }
        return vol;
    }
};
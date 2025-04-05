class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lftMax = 0;
        int rghtMax = 0;
        int i = 0, j = n - 1;
        int vol = 0;
        while(i < j){
            lftMax = max(lftMax, height[i]);
            rghtMax = max(rghtMax, height[j]);

            if(lftMax < rghtMax){
                vol += lftMax - height[i];
                i++;
            }
            else {
                vol += rghtMax - height[j];
                j--;
            }
        }
        return vol;
    }
};
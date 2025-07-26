class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int rght = 0, lft = 0;
        int maxLen = 0, x = 0;

        while(rght < n){
            if(nums[rght] == 0){
                x++;
            }
            while(x > k){
                if(nums[lft] == 0){
                    x--;
                }
                lft++;
            }
            maxLen = max(maxLen, rght - lft + 1);
            rght++;
        }
        return maxLen;
    }
};
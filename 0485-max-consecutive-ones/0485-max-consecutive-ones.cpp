class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int len = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                len++;
            }
            else{
                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};
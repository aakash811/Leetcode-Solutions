class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                maxLen = max(maxLen, cnt);
                cnt = 0;
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
};
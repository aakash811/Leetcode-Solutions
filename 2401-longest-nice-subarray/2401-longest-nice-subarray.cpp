class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int l = 0;
        int usedBits = 0;

        for(int i = 0; i < n; i++){
            while((usedBits & nums[i]) != 0){
                usedBits ^= nums[l];
                l++;
            }

            usedBits |= nums[i];
            maxLen = max(maxLen, i - l + 1);
        }

        return maxLen;
    }
};
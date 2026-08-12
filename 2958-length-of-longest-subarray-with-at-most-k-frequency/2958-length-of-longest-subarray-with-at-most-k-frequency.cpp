class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>ump;
        int left = 0;
        int right = 0;
        int maxLen = 0;

        while(right < n){
            ump[nums[right]]++;
            if(ump[nums[right]] > k){
                while(ump[nums[right]] > k){
                    ump[nums[left]]--;
                    left++;
                }
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
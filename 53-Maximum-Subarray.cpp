class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
      int res = INT_MIN;
      int maxEnd = INT_MIN;

      for(int i = 0; i < n; i++)
      {
        int maxEnd = max(maxEnd + nums[i], nums[i]);
        res = max(res, maxEnd);
      }  

      return res;
    }
};
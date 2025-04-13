class Solution {
public:
    int jump(vector<int>& nums) {
     for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

    //   for(int i = 0; i < nums.size(); i++){
    //     cout<<nums[i]<<" ";
    //   }
    //   cout<<endl;
      int idx = 0;
      int ans = 0;

      while(idx < nums.size() - 1)
      {
        ans++;
        // cout<<nums[idx]<<endl;
        idx = nums[idx];
      }

      return ans;
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int cnt_asc = 1;
        int cnt_dsc = 1;
        int max_cnt = 0;
        if(n == 1)
        {
            return 1;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] < nums[i + 1])
            {
                cnt_dsc = 1;
                cnt_asc++;
            }
            else if(nums[i] > nums[i + 1])
            {
                cnt_asc = 1;
                cnt_dsc++;
            }
            else 
            {
                cnt_asc = cnt_dsc = 1;
            }
            max_cnt = max(max_cnt, max(cnt_asc, cnt_dsc));
        } 
        return max_cnt;
    }
};
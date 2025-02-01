class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int maxCnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                cnt ++;
            }
            else
            {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }

        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};
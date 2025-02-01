class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        if(nums[0] % 2 == 0)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        for(int i = 1; i < n; i++)
        {
            if(flag == true)
            {
                if(nums[i] % 2 != 0)
                {
                    flag = false;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(nums[i] % 2 == 0)
                {
                    flag = true;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
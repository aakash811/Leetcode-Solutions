class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i + 1; j < n - 2; j++)
            {
                long long newTarget = target - 1LL * nums[i] - 1LL * nums[j];
                vector<int>temp;
                int idx1 = j + 1;
                int idx2 = n - 1;

                while(idx1 < idx2)
                {
                    int sum = nums[idx1] + nums[idx2];
                    if(sum > newTarget)
                    {
                        idx2--;
                    }
                    else if(sum < newTarget)
                    {
                        idx1++;
                    }
                    else
                    {
                        temp = {nums[i], nums[j], nums[idx1], nums[idx2]};
                        res.push_back(temp);
                        int tidx1 = idx1, tidx2 = idx2;
                        while(idx1 < idx2 && nums[idx1] == nums[tidx1]){idx1++;}
                        while(idx1 < idx2 && nums[idx2] == nums[tidx2]){idx2--;}
                    }
                }
                while(j < n - 2 && nums[j] == nums[j + 1]){j++;}
            }
            while(i < n - 3 && nums[i] == nums[i + 1]){i++;}
        }
        return res;
    }
};
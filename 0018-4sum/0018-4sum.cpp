class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; 

                int k = j + 1;
                int l = n - 1;
                long long tar = 1LL * target - nums[i] - nums[j];

                while(k < l) {
                    long long sum = 1LL * nums[k] + nums[l];
                    if(sum < tar) {
                        k++;
                    }
                    else if(sum > tar) {
                        l--;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int val_k = nums[k], val_l = nums[l];
                        while(k < l && nums[k] == val_k) k++; 
                        while(k < l && nums[l] == val_l) l--;
                    }
                }
            }
        }

        return res;
    }
};

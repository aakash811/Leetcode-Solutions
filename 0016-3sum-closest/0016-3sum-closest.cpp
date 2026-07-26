class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        int minDiff = INT_MAX;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target;
                // cout<<"diff -> " << diff<<endl;
                // cout<<"sum -> "<< sum<<endl;

                if(diff == 0){
                    return target;
                }
                if(abs(diff) < minDiff){
                    minDiff = abs(diff);
                    // cout<<"minDiff -> " << minDiff<<endl;
                    res = sum;
                }
                else if(diff < 0){
                    j++;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                }
                else if(diff > 0){
                    k--;
                    while(j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }
            }
        }
        return res;
    }
};
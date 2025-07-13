class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        int lft = 0, res = 0;

        sort(nums.begin(), nums.end());
        for(int rght = 0; rght < n; rght++){
            sum += nums[rght];

            while((long long)nums[rght] * (rght - lft + 1) - sum > k){
                sum -= nums[lft];
                lft++;
            }

            res = max(res, rght - lft + 1);
        }
        return res;
    }
};
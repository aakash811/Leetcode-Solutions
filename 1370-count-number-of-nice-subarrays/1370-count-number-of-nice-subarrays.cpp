class Solution {
public:
    int solve(vector<int>& nums, int k){
        int res = 0;
        int lft = 0, rght = 0;
        int n = nums.size();

        while(rght < n){
            k -= nums[rght] % 2;
            while(k < 0){
                k += nums[lft++] % 2;
            }
            res += rght - lft + 1;
            rght++;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
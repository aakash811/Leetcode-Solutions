class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int lft = 0, rght = 0;
        int cnt = 0;
        int x = 0;

        while(rght < n){
            if(nums[rght] % 2 == 1){
                x++;
            }
            while(x > k){
                if(nums[lft] % 2 == 1){
                    x--;
                }
                lft++;
            }

            cnt += rght - lft + 1;
            rght++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
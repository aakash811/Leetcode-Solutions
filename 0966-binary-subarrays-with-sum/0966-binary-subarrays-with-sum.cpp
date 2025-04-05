class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int lft = 0, rght = 0;
        int lft2 = 0, rght2 = 0;
        int sum = 0;
        int sum2 = 0;
        int cnt = 0;
        int cnt2 = 0;

        while(rght < n){
            sum += nums[rght];
            while(sum > goal && lft <= rght){
                sum -= nums[lft];
                lft++;
            }
            cnt += rght - lft + 1;
            rght++;
        }

        while(rght2 < n){
            sum2 += nums[rght2];
            while(sum2 > goal - 1 && lft2 <= rght2){
                sum2 -= nums[lft2];
                lft2++;
            }
            cnt2 += rght2 - lft2 + 1;
            rght2++;
        }

        return cnt - cnt2;
    }
};
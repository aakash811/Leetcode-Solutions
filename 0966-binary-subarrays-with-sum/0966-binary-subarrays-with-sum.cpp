class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size(); 
        int lft = 0, rght = 0;
        int cnt = 0;
        int sum = 0;
        
        while(rght < n){
            sum += nums[rght];
            while(sum > goal && lft <= rght){
                sum -= nums[lft];
                lft++;
            }
            cnt += rght - lft + 1;
            rght++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int lft = 0, rght = 0;
        int cnt = 0;
        unordered_map<int, int>ump;
        
        while(rght < n){
            ump[nums[rght]]++;

            while(ump.size() > k){
                ump[nums[lft]]--;
                if(ump[nums[lft]] == 0){
                    ump.erase(nums[lft]);
                }
                lft++;
            }

            cnt += rght - lft + 1;
            rght++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
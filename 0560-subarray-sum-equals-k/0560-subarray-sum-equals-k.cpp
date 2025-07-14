class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>ump;
        ump[0] = 1;
        int preSum = 0;
        int cnt = 0;

        for(int num : nums){
            preSum += num;
            if(ump.count(preSum - k)){
                cnt += ump[preSum - k];
            }
            ump[preSum]++;
        }

        return cnt;
    }
};
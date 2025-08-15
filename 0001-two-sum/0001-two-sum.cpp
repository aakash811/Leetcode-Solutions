class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>ump;
        int sum = 0;

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(ump.find(complement) != ump.end()){
                return {i, ump[complement]};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};
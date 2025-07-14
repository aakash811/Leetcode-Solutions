class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>ump;

        for(int i = 0; i < n; i++){
            int comp = target - nums[i];
            if(ump.find(comp) != ump.end()){
                return {ump[comp], i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};
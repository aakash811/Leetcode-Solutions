class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>uset;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                uset.insert(nums[i]);
            }
        }

        if(uset.size() == 0){
            return *max_element(nums.begin(), nums.end());
        }

        return accumulate(uset.begin(), uset.end(), 0);
    }
};
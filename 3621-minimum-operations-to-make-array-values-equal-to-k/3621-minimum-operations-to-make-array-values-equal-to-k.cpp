class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>ump;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < k){
                return -1;
            }
            ump[nums[i]]++;
        }

        if(ump.find(k) != ump.end())
        {
            return ump.size() - 1;
        }
        return ump.size();
    }
};
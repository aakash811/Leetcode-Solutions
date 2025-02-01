class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>ump;
        int thres = nums.size()/2;
        for(int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
            if(ump[nums[i]] > thres)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
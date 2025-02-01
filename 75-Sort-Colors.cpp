class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>ump;

        for(int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }

        int idx = 0;
        for(int i = 0; i < 3; i++)
        {
            int freq = ump[i];
            for(int j = 0; j < freq; j++)
            {
                nums[idx] = i;
                idx++;
            }
        }
    }
};
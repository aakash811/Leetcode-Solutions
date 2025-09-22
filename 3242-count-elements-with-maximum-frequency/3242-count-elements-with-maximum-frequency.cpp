class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>ump;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            ump[nums[i]]++;
        }

        int max_freq = ump[nums[0]];
        int cnt=0;
        for(auto it : ump)
        {
            if(it.second > max_freq)
            {
                max_freq = it.second;
                cnt = it.second;
            }
            else if(it.second == max_freq)
            {
                cnt += it.second;
            }
            else
            {
                continue;
            }
        }
        return cnt;
    }
};
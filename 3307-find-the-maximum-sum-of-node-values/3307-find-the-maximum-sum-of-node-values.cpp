class Solution 
{
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long long baseSum = 0;
        vector<int> gains;

        for (int num : nums) 
        {
            int xorVal = num ^ k;
            int gain = xorVal - num;
            baseSum += num;
            gains.push_back(gain);
        }

        sort(gains.rbegin(), gains.rend());

        long long gain = 0, curr = 0;
        int count = 0;

        for (int g : gains) 
        {
            curr += g;
            count++;
        
            if (count % 2 == 0) 
            {
                gain = max(gain, curr);
            }
        }

        return baseSum + gain;
    }
};
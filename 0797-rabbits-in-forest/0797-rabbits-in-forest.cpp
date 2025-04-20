class Solution {
public:
    int numRabbits(vector<int>& nums, int sum = 0) {
        unordered_map <int,int> mpp;
        for (int i : nums) mpp[i]++;

        for (auto it : mpp)
        sum += ceil((double)it.second / (it.first + 1)) * (it.first + 1);
        return sum;
    }
};
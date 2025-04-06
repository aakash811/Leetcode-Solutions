class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unordered_map<int, set<int>> subsets;
        subsets[-1] = set<int>();
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            set<int> maxSubset;
            for (auto& it : subsets) {
                if (num % it.first == 0 && it.second.size() > maxSubset.size()) {
                    maxSubset = it.second;
                }
            }
            maxSubset.insert(num);
            subsets[num] = maxSubset;
        }
        vector<int> result;
        set<int> maxSet;
        for (auto& it : subsets) {
            if (it.second.size() > maxSet.size()) {
                maxSet = it.second;
            }
        }
        copy(maxSet.begin(), maxSet.end(), back_inserter(result));
        return result;
    }
};
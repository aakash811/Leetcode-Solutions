class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : uset) {
            if (uset.find(num - 1) == uset.end()) {
                int currNum = num;
                int currLen = 1;

                while (uset.find(currNum + 1) != uset.end()) {
                    currNum++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};

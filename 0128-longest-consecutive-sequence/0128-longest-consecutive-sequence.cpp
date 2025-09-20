class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int maxLen = 0;

        for(auto it : uset){
            if(uset.find(it - 1) == uset.end()){
                int curr = it;
                int currLen = 1;

                while(uset.find(curr + 1) != uset.end()){
                    curr++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};
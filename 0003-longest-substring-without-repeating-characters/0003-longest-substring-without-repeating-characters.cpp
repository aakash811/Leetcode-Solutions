class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int lft = 0, rght = 0;
        unordered_map<char, int>ump;
        int maxLen = 0;

        while(rght < n){
            ump[s[rght]]++;
            while(ump[s[rght]] > 1){
                ump[s[lft]]--;
                lft++;
            }

            maxLen = max(maxLen, rght - lft + 1);
            rght++;
        }

        return maxLen;
    }
};
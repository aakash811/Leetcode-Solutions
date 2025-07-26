class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lft = 0, rght = 0;
        int maxFreq = 0, maxLen = 0;
        unordered_map<char, int>ump;

        while(rght < n){
            ump[s[rght]]++;
            maxFreq = max(maxFreq, ump[s[rght]]);
            while(((rght - lft + 1) - maxFreq) > k){
                ump[s[lft]]--;
                lft++;
            }
            maxLen = max(rght - lft + 1, maxLen);
            rght++;
        }
        return maxLen;
    }
};
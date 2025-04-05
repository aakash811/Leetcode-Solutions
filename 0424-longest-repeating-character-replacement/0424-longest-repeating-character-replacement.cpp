class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int>ump;
        int lft = 0, rght = 0;
        int maxFreq = 0;
        int maxLen = 0;
        int cnt = 0;

        while(rght < n){
            ump[s[rght]]++;
            maxFreq = max(maxFreq, ump[s[rght]]);

            while(((rght - lft + 1) - maxFreq) > k){
                ump[s[lft]]--;
                lft++;
            }
            maxLen = max(maxLen, rght - lft + 1);
            rght++;
        }

        return maxLen;
    }
};
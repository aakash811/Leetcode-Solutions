class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLen = INT_MIN;
        unordered_map<char, int>ump;
        
        while(right < n){
            ump[s[right]]++;
            maxFreq = max(maxFreq, ump[s[right]]);
            while((right - left + 1) - maxFreq > k){
                ump[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
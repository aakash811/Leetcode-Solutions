class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>ump;

        int left = 0;
        int right = 0;
        int maxLen = 0;

        while(right < n){
            ump[s[right]]++;
            while(ump[s[right]] > 2){
                ump[s[left]]--;
                if(ump[s[left]] == 0){
                    ump.erase(s[left]);
                }
                left++;    
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
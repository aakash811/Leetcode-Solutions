class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>vec(256, -1);
        int maxLen = 0;
        int left = 0;
        int right = 0;

        while(right < n){
            if(vec[s[right]] != -1){
                maxLen = max(maxLen, right - left);  
                left = max(left, vec[s[right]] + 1);
                vec[s[right]] = right;
            }
            vec[s[right]] = right;
            right++;
        }

        maxLen = max(maxLen, right - left);
        return maxLen;
    }
};
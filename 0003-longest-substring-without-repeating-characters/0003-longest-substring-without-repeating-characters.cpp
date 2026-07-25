class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lft = 0, rght = 0;
        int n = s.size();
        vector<int>mpp(256, -1);
        int len = 0;

        while(rght < n){
            if(mpp[s[rght]] != -1){
                lft = max(lft, mpp[s[rght]] + 1);
            }

            mpp[s[rght]] = rght;
            len = max(len, rght - lft + 1);
            rght++;    
        }

        return len;
    }
};
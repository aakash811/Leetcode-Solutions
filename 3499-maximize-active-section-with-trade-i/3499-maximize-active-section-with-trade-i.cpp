class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cntOne = count(s.begin(), s.end(), '1');

        int i = 0;
        int res = 0;
        int prev = INT_MIN, curr = 0;

        while(i < n){
            int start = i;

            while(i < n && s[i] == s[start]){
                i++;
            }
            if(s[start] == '0'){
                curr = i - start;
                res = max(res, prev + curr);
                prev = curr;
            }
        }

        return cntOne + res;
    }
};
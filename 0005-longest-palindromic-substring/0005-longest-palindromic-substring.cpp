class Solution {
public:
    string solve(string s, int l, int r){
        while (l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);   
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;

        string res = "";
        for(int i = 1; i < n - 1; i++){
            string x = solve(s, i, i);
            if(maxLen < x.size()){
                maxLen = x.size();
                res = x;
            }
        }

        for(int i = 1; i < n - 2; i++){
            string y = solve(s, i, i + 1);
            if(maxLen < y.size()){
                maxLen = y.size();
                res = y;
            }
        }

        return res;
    }
};
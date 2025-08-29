class Solution {
public:
    vector<int>solve(string s){
        int n = s.size();
        vector<int>lps(n, 0);
        int j = 0;
        
        for(int i = 1; i < n; i++){
            while(j > 0 && s[i] != s[j]){
                j = lps[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            lps[i] = j;
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        vector<int>lps = solve(combined);

        int lpsLen = lps.back();
        return rev.substr(0, n - lpsLen) + s;
    }
};
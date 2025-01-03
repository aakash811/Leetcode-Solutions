class Solution {
public:
    bool checkVowel(string& s) {
        int n = s.size();
        return (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
               (s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = words.size();

        vector<int> presum(m);
        vector<int> res(n);    

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (checkVowel(words[i])) {
                cnt++;
            }
            presum[i] = cnt; 
        }

        for (int i = 0; i < n; i++) { 
            int start = queries[i][0];
            int end = queries[i][1];

            if (start == 0) {
                res[i] = presum[end]; 
            } else {
                res[i] = presum[end] - presum[start - 1]; 
            }
        }

        return res;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int>ump;
        for(int i = 0; i < m; i++){
            ump[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int remChar = m;
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;

        while(right < n){
            if(ump.find(s[right]) != ump.end() && ump[s[right]] > 0){
                remChar--;
            }
            ump[s[right]]--;

            if(remChar == 0){
                while(!(ump.find(s[left]) != ump.end() && ump[s[left]] == 0)){
                    ump[s[left]]++;
                    left++;
                }

                if(right - left + 1 < minLen){
                    minLen = min(minLen, right - left + 1);
                    start = left;
                    end = right;
                }

                ump[s[left]]++;
                remChar++;
                left++;
            }

            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
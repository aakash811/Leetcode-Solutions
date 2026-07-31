class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n < m){
            return "";
        }

        unordered_map<char, int>ump;
        for(int i = 0; i < m; i++){
            ump[t[i]]++;
        }

        int remChar = m;
        int right = 0;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        int end = INT_MAX;

        while(right < n){
            if(ump.find(s[right]) != ump.end() && ump[s[right]] > 0){
                remChar--;
            } 
            ump[s[right]]--;

            if(remChar == 0){
               while(true){
                if(ump.find(s[left]) != ump.end() && ump[s[left]] == 0){
                    break;
                }
                ump[s[left]]++;
                left++;
               }

               if(right - left + 1 < minLen){
                start = left;
                end = right;
                minLen = right - left + 1;
               }

               ump[s[left]]++;
               remChar++;
               left++;
            }
            right++;
        }

        return end == INT_MAX ? "" : s.substr(start, minLen);
    }
};
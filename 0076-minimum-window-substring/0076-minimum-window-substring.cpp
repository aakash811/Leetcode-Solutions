class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size()){
            return "";
        }

        int n = s.size(), m = t.size();
        int lft = 0, rght = 0;
        int cnt = m, minLen = INT_MAX;
        int st = 0;
        vector<int>map(128, 0);

        for(int i = 0; i < m; i++){
            map[t[i]]++;
        }

        while(rght < n){
            if(map[s[rght++]]-- > 0){
                cnt--;
            }

            while(cnt == 0){
                if(rght - lft < minLen){
                    st = lft;
                    minLen = rght - lft;
                }

                if(map[s[lft++]]++ == 0){
                    cnt++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(st, minLen);
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n == 0 || m == 0 || n < m){
            return "";
        }
        
        int lft = 0, rght = 0, cnt = m, st = 0;
        int minLen = INT_MAX;
        vector<int>map(128, 0);

        for(int i = 0; i < m; i++){
            map[t[i]]++;
        }

        while(rght < n){
            if(map[s[rght]]-- > 0){
                cnt--;
            }

            while(cnt == 0){
                if(rght - lft + 1 < minLen){
                    st = lft;
                    minLen = rght - lft + 1;
                }

                if(map[s[lft]]++ == 0){
                    cnt++;
                }
                lft++;
            }
            rght++;
        }

        return minLen == INT_MAX ? "" : s.substr(st, minLen);
    }
};
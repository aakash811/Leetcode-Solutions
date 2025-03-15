class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            vector<int>alph(26, 0);
            for(int j = i; j < s.size(); j++){
                char ch = s[j];
                alph[ch - 'a']++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it : alph){
                    if(it > 0){
                        mini = min(mini, it);
                        maxi = max(maxi, it);
                    }
                }
                res += maxi - mini;
            }
        }
        return res;
    }
};
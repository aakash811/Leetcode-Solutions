class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n  = strs.size();
        string pref = "";

        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs[0].size(); i++){
            if(strs[0][i] != strs[strs.size() - 1][i]){
                return pref;
            }
            pref += strs[0][i];
        }
        return pref;
    }
};
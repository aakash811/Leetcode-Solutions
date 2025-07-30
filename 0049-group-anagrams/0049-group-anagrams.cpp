class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>ump;

        for(int i = 0; i < n; i++){
            vector<int>cnt(26, 0);
            for(char ch : strs[i]){
                cnt[ch - 'a']++;
            }

            string key = "";
            for(int j = 0; j < 26; j++){
                key += "#" + to_string(cnt[j]);
            }

            ump[key].push_back(strs[i]);
        }

        vector<vector<string>>res;
        for(auto it : ump){
            res.push_back(it.second);
        }
        return res;
    }
};
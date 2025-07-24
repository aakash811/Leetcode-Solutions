class Solution {
public:
    bool solve(unordered_set<string>& uset, string s, int idx, vector<int>& memo){
        if(idx == s.size()){
            return true;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }

        for(int i = idx; i < s.size(); i++){
            string word = s.substr(idx, i - idx + 1);
            if(uset.find(word) != uset.end() && solve(uset, s, i + 1, memo)){
                return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>uset(wordDict.begin(), wordDict.end());
        vector<int>memo(s.size(), -1);
        return solve(uset, s, 0, memo);
    }
};
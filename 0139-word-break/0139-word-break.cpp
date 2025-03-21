class Solution {
public:
    bool solve(string s, unordered_set<string>& wordSet, int idx, vector<int>& memo){
        if(idx == s.size()){
            return true;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }

        for(int i = idx; i < s.size(); i++){
            string word = s.substr(idx, i - idx + 1);
            if(wordSet.find(word) != wordSet.end() && solve(s, wordSet, i + 1, memo)){
                return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(), wordDict.end());
        vector<int>memo(s.size(), -1);
        return solve(s, wordSet, 0, memo);
    }
};
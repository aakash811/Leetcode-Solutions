class Solution {
public:
    vector<vector<char>> vec = {
        {}, {}, 
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'}, 
        {'g', 'h', 'i'}, 
        {'j', 'k', 'l'}, 
        {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, 
        {'t', 'u', 'v'}, 
        {'w', 'x', 'y', 'z'}
    };
    void solve(string digits, vector<string>& res, int idx, string str){
        if(idx == digits.size()){
            res.push_back(str);
            return;
        }

        for(auto it : vec[digits[idx] - '0']){
            str.push_back(it);
            solve(digits, res, idx + 1, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>res;
        solve(digits, res, 0, "");
        if(res[0] == ""){
            return {};
        }
        return res;  
    }
};
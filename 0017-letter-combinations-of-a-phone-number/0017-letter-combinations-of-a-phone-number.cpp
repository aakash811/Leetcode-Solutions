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

    void solve(string digits, vector<string>& ds, int i, string str){
        if(i == digits.size()){
            ds.push_back(str);
            return;
        }

        for(auto it : vec[digits[i] - '0']){
            str.push_back(it);
            solve(digits, ds, i + 1, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ds;
        solve(digits, ds, 0, "");
        if(ds[0] == ""){
            return {};
        }
        return ds;
    }
};
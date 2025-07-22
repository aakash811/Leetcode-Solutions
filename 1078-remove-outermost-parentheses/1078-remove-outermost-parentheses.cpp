class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int sum = 1;
        vector<int>res;
        res.push_back(0);
        for(int i = 1; i < n; i++){
            if(s[i] == '('){
                sum += 1;
            }
            else{
                sum -= 1;
            }

            if(sum == 0){
                res.push_back(i);
                if(i != n - 1){
                    res.push_back(i + 1);
                }
            }
        }

        string str = "";
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(i == res[idx]){
                idx++;
                continue;
            }
            else{
                str += s[i];
            }
        }
        return str;
    }
};
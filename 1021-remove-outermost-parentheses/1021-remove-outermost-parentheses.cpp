class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char>stk;
        string str = "";
        int idx = 0;

        for(int i = 0; i < n; i++){
            if(!stk.empty() && stk.top() == '(' && s[i] == ')'){
                stk.pop();
                if(stk.empty()){
                    idx = 0;
                    continue;
                }
                else{
                    str += s[i];
                }
            }
            else if(s[i] == '('){
                stk.push(s[i]);
                if(idx != 0){
                    str += s[i];
                }
                idx++;
            }
        }
        return str;
    }
};
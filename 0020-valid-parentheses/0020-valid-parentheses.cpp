class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else if(!stk.empty() && (stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']')){
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
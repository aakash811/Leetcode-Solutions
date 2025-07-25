class Solution {
public:
    bool isValid(string s) {
        stack<int>stk;

        for(int i = 0; i < s.size(); i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else if(!stk.empty() && (stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']')){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};
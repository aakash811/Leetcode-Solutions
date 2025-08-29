class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                stk.push('(');
            }
            else{
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                }
                else{
                    stk.push(')');
                }
            }
        }

        return stk.size();
    }
};
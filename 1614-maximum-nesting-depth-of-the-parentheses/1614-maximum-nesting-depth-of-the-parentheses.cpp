class Solution {
public:
    int maxDepth(string s) {
        stack<char>stk;
        int n = s.size();

        int maxDepth = 0;
        int depth = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
               stk.push(s[i]); 
               depth++;
            }
            else if(!stk.empty() && stk.top() == '(' && s[i] == ')'){
                stk.pop();
                maxDepth = max(depth, maxDepth);
                depth--;
            }
            else{
                continue;
            }
        }
        maxDepth = max(depth, maxDepth);
        return maxDepth;
    }
};
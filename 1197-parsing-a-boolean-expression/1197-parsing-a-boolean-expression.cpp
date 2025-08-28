class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>stk;

        for(char ch : expression){
            if(ch == ')'){
                vector<char>operands;
                while(!stk.empty() && stk.top() != '('){
                    operands.push_back(stk.top());
                    stk.pop();
                }

                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                }

                if(!stk.empty()){
                    char op = stk.top();
                    stk.pop();

                    bool res = (operands[0] == 't');

                    if(op == '!'){
                        res = !res;
                    }
                    else if(op == '&'){
                        res = true;
                        for(char c : operands){
                            res = res & (c == 't');
                        }
                    }
                    else if(op == '|'){
                        res = false;
                        for(char c : operands){
                            res = res || (c == 't');
                        }
                    }

                    stk.push(res ? 't' : 'f');
                }
            }
            else if(ch != ',' && ch != '('){
                stk.push(ch);
            }
            else if(ch == '('){
                stk.push(ch);
            }
        }

        if(!stk.empty()){
            return stk.top() == 't';
        }

        return false;
    }
};
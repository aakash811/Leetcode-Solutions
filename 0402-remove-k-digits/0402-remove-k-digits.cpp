class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        string res = "";
        int n = num.size();

        for(int i = 0; i < n; i++){
            while(k > 0 && !stk.empty() && stk.top() > num[i]){
                --k;
                stk.pop();
            }
            if(stk.empty() && num[i] == '0'){
                continue;
            }
            else{
                stk.push(num[i]);
            }
        }

        while(k--){
            if(!stk.empty()){   
                stk.pop();
            }
        }

        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
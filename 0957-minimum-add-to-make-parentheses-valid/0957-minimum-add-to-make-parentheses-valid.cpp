class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                open++;
            }
            else{
                if(open == 0){
                    cnt++;
                }
                else{
                    open--;
                }
            }
        }
        return open + cnt;
    }
};
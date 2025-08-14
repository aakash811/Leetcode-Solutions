class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int cnt = 1;
        int res = -1;
        for(int i = 0; i < n - 1; i++){
            if(num[i] == num[i + 1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            if(cnt == 3){
                res = max(res, num[i] - '0'); 
                // cout<<num[i] - '0'<<endl;
                cnt = 0;
            }
        }

        if(res == -1){
            return "";
        }
        string ch = to_string(res);
        string ans = ch + ch + ch;
        return ans;
    }
};
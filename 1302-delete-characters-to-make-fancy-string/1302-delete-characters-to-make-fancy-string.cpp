class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 1;
        ans.push_back(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ans.back()){
                if(cnt == 2){
                    continue;
                }
                else
                {
                    ans.push_back(s[i]);
                    cnt++;
                }
            }
            else{
            ans.push_back(s[i]);
            cnt = 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size(); 
        vector<string>res;
        
        for(int i = 0; i < n; i += k){
            string str = "";
            for(int j = 0; j < k; j++){
                if(i + j < n){
                    str += s[i + j];
                }else{
                    str += fill;
                }
            }
            res.push_back(str);
        }

        return res;
    }
};
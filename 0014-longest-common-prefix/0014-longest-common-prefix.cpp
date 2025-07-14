class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        // int count=0;
        // for(int i=0;i<strs[0].length();i++){
        //     char x=strs[0][i];
            
        //     for(int j=0;j<n;j++){
                
        //         if(strs[j].length()<i || strs[j][i] !=x){
        //             return 
        //         }
        //     }
            
        // }
        
        
        
        
        
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++){
            string s = strs[i];
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                string t = strs[j];
                int len = min(s.size(), t.size());
                int sz = 0;
                for(int k = 0; k < len; k++){
                    if(s[k] != t[k]){
                        break;
                    }
                    else{
                        sz++;
                    }
                }
                
                minLen = min(minLen, sz);
            }
        }
        
        return strs[0].substr(0, minLen);
    }
};
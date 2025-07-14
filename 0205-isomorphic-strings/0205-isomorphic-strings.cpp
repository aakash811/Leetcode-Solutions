class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]!=t[i]){
                return false;
            }
            mpp[s[i]]=t[i];
        }
        mpp.clear();
        for(int i=0;i<n;i++){
            if(mpp.find(t[i])!=mpp.end() && mpp[t[i]]!=s[i]){
                return false;
            }
            mpp[t[i]]=s[i];
        }
        
        return true;
       
         
         
        
       
    }
};
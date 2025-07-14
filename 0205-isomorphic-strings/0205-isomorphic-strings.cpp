class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>ump;
        unordered_map<char, char>ump2;
        
        
        for(int i = 0; i < s.size(); i++){
            if(ump.find(s[i]) != ump.end() && ump[s[i]] != t[i]){
                return false;
            } 
            if(ump2.find(t[i]) != ump2.end() && ump2[t[i]] != s[i]){
                return false;
            } 
            ump[s[i]] = t[i];
            ump2[t[i]] = s[i];
        }
        return true;
    }
};
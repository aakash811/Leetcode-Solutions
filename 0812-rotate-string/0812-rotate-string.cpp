class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        
        for(int i = n - 1; i >= 0; i--){
            char ch = s[n - 1];
            s.pop_back();
            s = ch + s;
            
            if(s == goal){
                return true;
            }
        }
        
        return false;
    }
};
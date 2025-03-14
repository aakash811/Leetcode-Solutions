class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        
        if(n != m) {
            return false;  
        }         

        if(s == goal){
            return true;
        }

        vector<int> idx;
        for(int i = 0; i < n; i++){
            if(goal[i] == s[0]){
                idx.push_back(i);
            }
        }

        // cout<<idx<<endl;
        string str = "";

        for(auto it : idx){
            for(int i = 0; i < n; i++){
                str += goal[(i + it) % n];
            }
            cout<<str<<endl;
            if(str == s){
                return true;
            }
            str = "";
        }
        return false;
    }
};
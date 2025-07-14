class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        
        for(int i = 0; i < n; i++){
            unordered_map<char, int>ump;
            for(int j = i; j < n; j++){
                ump[s[j]]++;
                int maxi = 0;
                int mini = INT_MAX;
                for(auto it : ump){
                    if(it.second > maxi){
                        maxi = it.second;
                    }
                    if(it.second < mini){
                        mini = it.second;
                    }
                }           
                res += maxi - mini;
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000},};
        
        int n = s.size();
        int num = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'I' && s[i + 1] == 'V' && i < n - 1){
                num += 4;
                i++;
            }
            else if(s[i] == 'I' && s[i + 1] == 'X' && i < n - 1){
                num += 9;
                i++;
            }
            else if(s[i] == 'X' && s[i + 1] == 'L' && i < n - 1){
                num += 40;
                i++;
            }
            else if(s[i] == 'X' && s[i + 1] == 'C' && i < n - 1){
                num += 90;
                i++;
            }
            else if(s[i] == 'C' && s[i + 1] == 'D' && i < n - 1){
                num += 400;
                i++;
            }
            else if(s[i] == 'C' && s[i + 1] == 'M' && i < n - 1){
                num += 900;
                i++;
            }
            else {
                num += mp[s[i]];
            }
            cout<<num<<endl;
        }

        return num;
    }
};
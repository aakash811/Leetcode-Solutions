class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                s.erase(0, i);
                break;
            }
        }

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == ' ' && s[i + 1] == ' '){
                s.erase(i, 1);
                i--;
            }
        }

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != ' '){
                s.erase(i + 1, s.size() - i + 1);
                break;
            }
        }

        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin() + idx, s.begin() + i);
                idx = i + 1;
            }
            if(i == s.size() - 1){
                reverse(s.begin() + idx, s.end());
            }
        }
        return s;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        for(char& it : s){
            if(std::isupper(it)){
                it = std::tolower(it);
            }
        }

        s.erase(remove_if(s.begin(), s.end(), [](char c){
            return !std::isalnum(c);
        }),s.end());

        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
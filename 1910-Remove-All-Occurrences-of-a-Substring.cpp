class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for(char c : s) {
            result.push_back(c);
            if(result.length() >= part.length() && 
               result.substr(result.length() - part.length()) == part) {
                result.resize(result.length() - part.length());
            }
        }
        return result;
    }
};
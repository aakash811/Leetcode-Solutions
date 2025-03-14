class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str;
        vector<string>words;

        while(ss >> str){
            words.push_back(str);  
        }
        reverse(words.begin(), words.end());
        string res;

        for(int i = 0; i < words.size(); i++){
            res += words[i];
            if(i < words.size() - 1){
                res += " ";
            }
        }
        return res;
    }
};
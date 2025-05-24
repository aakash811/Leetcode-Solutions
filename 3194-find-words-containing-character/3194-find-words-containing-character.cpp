class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>res;
        for(int i = 0; i < n; i++){
            string str = words[i];
            for(char ch : str){
                if(ch == x){
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    bool checkValidString(string s) {
        vector<int>vec = {0, 0, 0};

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                vec[0]++;
            }
            else if(s[i] == ')'){
                if(vec[0] > 0)
                {
                    vec[0]--;
                }
                else if(vec[2] > 0){
                    vec[2]--;
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '*'){
                vec[2]++;
            }
        }

        vector<int>vec1 = {0, 0, 0};

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ')'){
                vec1[0]++;
            }
            else if(s[i] == '('){
                if(vec1[0] > 0)
                {
                    vec1[0]--;
                }
                else if(vec1[2] > 0){
                    vec1[2]--;
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '*'){
                vec1[2]++;
            }
        }

        return true;
    }
};
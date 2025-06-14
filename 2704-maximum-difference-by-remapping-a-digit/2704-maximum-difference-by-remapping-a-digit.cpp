class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string mini = str;
        string maxi = str;

        char x1, x2;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '9'){
                continue;
            }
            else{
                x1 = str[i];
                break;
            }
        }

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0'){
                continue;
            }
            else{
                x2 = str[i];
                break;
            }
        }

        for(int i = 0; i < str.size(); i++){
            if(maxi[i] == x1){
                maxi[i] = '9';
            }
            if(mini[i] == x2){
                mini[i] = '0';
            }
        }

        int minNum = stoi(mini);
        int maxNum = stoi(maxi);

        return maxNum - minNum;
    }
};
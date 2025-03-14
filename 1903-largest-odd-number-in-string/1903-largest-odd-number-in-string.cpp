class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string maxOdd = "";

        int idx = -1;
        for(int i = n - 1; i >= 0; i--){
            if(num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9'){
                idx = i;
                break;
            }
        }

        if(idx >= 0){
            for(int i = 0; i <= idx; i++){
                maxOdd += num[i];
            }
        }
        return maxOdd;
    }
};
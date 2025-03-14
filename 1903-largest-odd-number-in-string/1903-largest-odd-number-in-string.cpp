class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string maxOdd = "";

        int idx = -1;
        for(int i = 0; i < n; i++){
            if(num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9'){
                idx = i;
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
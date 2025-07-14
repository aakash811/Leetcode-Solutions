class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        bool flag = true;
        for(int i = n - 1; i >= 0; i--){
            int x = num[i] - '0';
            if(x % 2 != 0){
                flag = false;
                num.erase(i + 1, n - 1);
                break;
            }
        }
        return !flag ? num : "";
    }
};
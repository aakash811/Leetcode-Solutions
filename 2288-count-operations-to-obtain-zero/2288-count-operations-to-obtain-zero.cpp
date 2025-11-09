class Solution {
public:
    void solve(int num1, int num2, int& res){
        if(num1 == 0 || num2 == 0){
            return;
        }
        if(num1 >= num2){
            int div = num1 / num2;
            num1 -= (num2 * div);
            res += div;
        }
        else{
            int div = num2 / num1;
            num2 -= (num1 * div);
            res += div;
        }
        solve(num1, num2, res);
    }

    int countOperations(int num1, int num2) {
        int res = 0;
        solve(num1, num2, res);
        return res;
    }
};
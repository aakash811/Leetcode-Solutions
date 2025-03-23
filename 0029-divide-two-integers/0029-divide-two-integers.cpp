class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(divisor == 1){
            return dividend;
        }

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        long long david = abs((long long)dividend);
        long long davis = abs((long long) divisor);
        long long res = 0;
        while(david >= davis){
            int bit = 0;
            while(david >= (davis << bit)){
                bit++;
            }
            bit--;
            david -= (davis << bit);
            res += (1 << bit);
        }

        return sign * res;
    }
};
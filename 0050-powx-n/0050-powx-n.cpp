class Solution {
public:
    double solve(double x, long long n){
        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 1.0 / solve(x, -n);
        }
        if(n % 2 != 0){
            return x * solve(x * x, (n - 1) / 2);
        }
        else{
            return solve(x * x, n / 2);
        }
    }

    double myPow(double x, int n) {
        return solve(x, 1LL * n);
    }
};
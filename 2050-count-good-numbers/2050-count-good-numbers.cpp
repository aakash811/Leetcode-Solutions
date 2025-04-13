class Solution {
public:
    long long int MOD = 1e9 + 7;
    long long solve(long long x, long long n){
        if(n == 0){
            return 1;
        }

        if(n % 2 != 0){
            return (x * solve((x * x) % MOD, (n - 1) / 2)) % MOD;
        }
        else{
            return solve((x * x) % MOD, n / 2);
        }
    }

    int countGoodNumbers(long long n) {
        long long odds = solve(4, n / 2);
        long long evens = solve(5, n / 2 + n % 2);

        return (odds * evens) % MOD;
    }
};
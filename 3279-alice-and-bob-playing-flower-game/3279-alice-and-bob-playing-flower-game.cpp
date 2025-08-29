class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = n / 2, oddM = m / 2, evenN = n / 2, evenM = m / 2;

        if(n % 2 == 1){
            oddN += 1;
        }
        if(m % 2 == 1){
            oddM += 1;
        }

        return 1LL * (oddN * evenM) + (oddM * evenN);
    }
};
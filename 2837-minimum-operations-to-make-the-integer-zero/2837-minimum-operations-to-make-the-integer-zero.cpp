class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int res = 1;
        while(true){
            long long x = num1 - 1LL * num2 * res;
            if(x < res){
                return -1;
            }
            if(res >= __builtin_popcountll(x)){
                return res;
            }
            res++;
        }
    }
};
class Solution {
public:
    char kthCharacter(int k) {
        int res = 0;
        int x;

        while(k != 1){
            x = __lg(k);
            if((1 << x) == k){
                x--;
            }
            k = k - (1 << x);
            res++;
        }

        return 'a' + res;
    }
};
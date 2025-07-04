class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int res = 0;
        int x;

        while(k != 1){
            x = __lg(k);
            if(((long long)1 << x) == k){
                x--;
            }
            k = k - ((long long)1 << x);
            if(operations[x]){
                res++;
            }
        }
        return 'a' + (res % 26);
    }
};
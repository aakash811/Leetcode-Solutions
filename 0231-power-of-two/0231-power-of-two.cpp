class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        int x = 1;
        if(n < 0){
            return false;
        }
        if(n % 2 == 1){
            cnt++;
        }
        for(int i = 0; i < 32; i++){
            x <<= 1;
            cnt += (x & n) ? 1 : 0;
        }
        return (cnt == 1);
    }
};
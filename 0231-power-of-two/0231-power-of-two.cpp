class Solution {
public:
    bool isPowerOfTwo(int n) {
        int bit = 1;

        for(int i = 0; i < 31; i++){
            if(bit == n){
                return true;
            }
            bit <<= 1;
        }
        return false;
    }
};
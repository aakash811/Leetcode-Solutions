class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = x;
        int res;
        while(lo <= hi){
            long long int mid = lo + (hi - lo) / 2;
            if(mid * mid <= x){
                res = mid;
                lo = mid + 1;
            }
            if(mid * mid > x){
                hi = mid - 1;
            }
        }
        return res;
    }
};
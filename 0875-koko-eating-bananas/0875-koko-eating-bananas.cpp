class Solution {
public:
    long long int solve(long long int x, vector<int>& piles){
        long long int res = 0;
        for(auto it : piles){
             res += ceil((double) it / (double) x);
        }
        return res;
    }
    long long int minEatingSpeed(vector<int>& piles, int h) {
        long long int lo = 1, hi = *max_element(piles.begin(), piles.end());

        while(lo <= hi){
            long long int mid = lo + (hi - lo) / 2;
            long long int time = solve(mid, piles);
            if(time <= h){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
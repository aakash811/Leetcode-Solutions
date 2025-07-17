class Solution {
public:
    long long solve(vector<int>& piles, int mid){
        long long time = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            time += ceil((double)piles[i] / (double) mid);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long lo = 1, hi = *max_element(piles.begin(), piles.end());

        while(lo <= hi){ 
            long long mid = lo + (hi - lo) / 2;
            long long time = solve(piles, mid);

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
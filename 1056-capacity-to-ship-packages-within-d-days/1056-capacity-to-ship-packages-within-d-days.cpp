class Solution {
public:
    bool solve(vector<int>& weights, int mid, int days) {
        int sum = 0;
        int cnt = 1; 
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                cnt++;             
                sum = weights[i];  
            } else {
                sum += weights[i];
            }
        }
        return cnt <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(solve(weights, mid, days)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
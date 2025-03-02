class Solution {
public:
    int solve(int x, vector<int>& weights){
        int n = weights.size();
        int sum = 0;
        int days = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            if(sum == x){
                days++;
                sum = 0;
            }
            else if(sum > x){
                days++;
                sum = weights[i];
            }
        }
        if(sum > 0){
            days++;
        }
        cout<<x<<" "<<days<<endl;
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end()), hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(solve(mid, weights) > days){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
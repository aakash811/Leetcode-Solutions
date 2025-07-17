class Solution {
public:
    bool solve(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0 ;
        int bouquet = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bouquet += cnt / k;
                cnt = 0;
            }
        }
        bouquet += (cnt / k);
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        if(n < 1LL * m * k){
            return -1;
        }

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(solve(bloomDay, mid, m, k)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
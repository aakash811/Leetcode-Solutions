class Solution {
public:
    bool isPossible(vector<int>& nums, int day, int m, int k)
    {
        int n = nums.size();
        int cnt = 0;
        int noBou = 0;

        for(int i =0 ;i < n; i++){
            if(nums[i] <= day){
                cnt++;
            }
            else{
                noBou += (cnt/k);
                cnt = 0;
            }
        }
        noBou += (cnt / k);
        return noBou >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        if(n < m * k){
            return -1;
        }

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(isPossible(bloomDay, mid, m, k)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
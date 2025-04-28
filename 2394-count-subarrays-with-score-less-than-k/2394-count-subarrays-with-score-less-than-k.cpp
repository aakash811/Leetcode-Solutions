class Solution {
public: 
    bool isVal(int mid, vector<long long>& pref, long long k, int idx){
        long long sum = pref[idx] - (mid > 0 ? pref[mid - 1] : 0);
        long long len = idx - mid + 1;
        return sum * len < k;
    }

    int solve(vector<long long>& pref, long long k, int lo, int hi, int idx){
        int ans = idx + 1; 
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(isVal(mid, pref, k, idx)){
                ans = mid;
                hi = mid - 1; 
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + nums[i];
        }

        long long cnt = 0;
        for(int i = 0; i < n; i++){
            int val = solve(pref, k, 0, i, i);
            cnt += (i - val + 1);
        }
        return cnt;
    }
};

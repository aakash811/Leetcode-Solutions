class Solution {
public:
    bool solve(vector<int>& nums, int mid, int k){
        int n = nums.size();
        int cnt = 0;
        int idx = 0;
        while(idx < n){
            if(nums[idx] <= mid){
                cnt++;
                idx += 2;
            } else{
                idx++;
            }
            if(cnt >= k){
                return true;
            } 
        }
        return (cnt >= k);
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(solve(nums, mid, k)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
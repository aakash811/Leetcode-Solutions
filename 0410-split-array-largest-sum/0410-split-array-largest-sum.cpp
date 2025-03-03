class Solution {
public:
    int solve(vector<int>& nums, int mid, int k){
        int cnt = 1;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(solve(nums, mid, k) > k){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        } 
        return lo;
    }
};
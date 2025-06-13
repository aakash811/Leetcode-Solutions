class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[n - 1] - nums[0];

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int pairs = 0;
            for(int i = 1; i < n; i++){
                if(mid >= nums[i] - nums[i - 1]){
                    pairs++;
                    i++;
                }
            }
            if(pairs >= p){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
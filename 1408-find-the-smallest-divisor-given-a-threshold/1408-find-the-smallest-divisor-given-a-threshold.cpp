class Solution {
public:
    int solve(int x, vector<int>& nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil(1.0 * nums[i] / x);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(solve(mid, nums) > threshold){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
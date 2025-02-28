class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int lo = 0, hi = n - 1;
        int idx = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(target == nums[mid]){
                return mid;
            }
            if(nums[mid] < target){
                idx = mid;
                lo = mid + 1;
            }
            if(nums[mid] > target){
                hi = mid - 1;
            }
        }

        if(nums[idx] > target){
            return idx; 
        }

        return idx + 1;
    }
};
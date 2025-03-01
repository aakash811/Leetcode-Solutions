class Solution {
public:
    int upbinarySearch(vector<int> &nums, int target){
        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2; 
            if(nums[mid] > target){
                hi = mid - 1;
            }
            if(nums[mid] < target){
                lo = mid + 1;
            }
            if(nums[mid] == target){
                return mid;
            }
        }
        return -1;
    }

    int lobinarySearch(vector<int> &nums, int target){
        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo + 1) / 2; 
            if(nums[mid] > target){
                hi = mid - 1;
            }
            if(nums[mid] < target){
                lo = mid + 1;
            }
            if(nums[mid] == target){
                return mid;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int upRange = upbinarySearch(nums, target);
        int lowRange = lobinarySearch(nums, target);
        int loLim = min(lowRange, upRange);
        int upLim = max(lowRange, upRange);
        return {loLim, upLim};
    }
};
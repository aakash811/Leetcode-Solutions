class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target){
                int lft = mid, rght = mid;
                while(lft >= 1 && nums[lft] == nums[lft - 1]){
                    lft--;
                }
                while(rght < n - 1 && nums[rght] == nums[rght + 1]){
                    rght++;
                }
                return {lft, rght};
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return {-1, -1};
    }
};
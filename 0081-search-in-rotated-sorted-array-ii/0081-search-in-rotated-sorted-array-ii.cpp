class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0, right = n - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[left]) {
                left++;
                continue;
            }
            if(nums[mid] >= nums[left]){
                if(nums[left] <= target && nums[mid] >= target){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            if(nums[mid] <= nums[right]){
                if(nums[mid] <= target && nums[right] >= target){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
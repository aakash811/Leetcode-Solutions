class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(nums[lo] > nums[hi]){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[lo]){
                lo = mid + 1;
            }
            else if(nums[mid] < nums[hi]){
                hi = mid;
            }
            else{
                lo++;
            }
        }
        return nums[lo];
    }
};
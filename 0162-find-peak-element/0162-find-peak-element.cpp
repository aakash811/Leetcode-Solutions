class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =  nums.size();
        int lo = 0, hi = n - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid + 1] > nums[mid]){
                lo = mid + 1;
            }
            else if (nums[mid - 1] > nums[mid]){
                hi = mid;
            }
            else{
                return mid;
            }
        }
        return lo;
    }
};
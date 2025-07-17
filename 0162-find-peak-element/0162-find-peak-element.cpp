class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(mid != n - 1 && nums[mid + 1] > nums[mid]){
                lo = mid + 1;
            }
            else if(mid != 0 && nums[mid - 1] > nums[mid]){
                hi = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
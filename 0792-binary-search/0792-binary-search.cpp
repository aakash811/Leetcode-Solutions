class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target){
                lo++;
            }
            else{
                hi--;
            }
        }

        return nums[lo] == target ? lo : -1;
    }
};
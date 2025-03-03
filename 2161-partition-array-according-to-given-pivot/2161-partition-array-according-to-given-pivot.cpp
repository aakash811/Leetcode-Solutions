class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n, 0);
        int lo = 0, hi = n - 1;
        
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                result[lo] = nums[i];
                lo++;
            }
            
            if (nums[j] > pivot) {
                result[hi] = nums[j];
                hi--;
            }
        }        
        while (lo <= hi) {
            result[lo] = pivot;
            lo++;
        }
        
        return result;
    }
};
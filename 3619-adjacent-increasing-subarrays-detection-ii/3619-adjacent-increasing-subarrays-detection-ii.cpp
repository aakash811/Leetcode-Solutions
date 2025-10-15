class Solution {
public:
    bool solve(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        for (int i = 0; i + 1 < n; i++) {
            if (left[i] >= k && right[i + 1] >= k)
                return true;
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n / 2;
        int res = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            
            if(solve(nums, mid)){
                res = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return res;
    }
};
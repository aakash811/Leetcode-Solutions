class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return 0;

        int product = 1;
        int cnt = 0;

        for(int left = 0, right = 0; right < n; right++){
            product *= nums[right];
            while(product >= k){
                product /= nums[left++];
            }
            cnt += right - left + 1;
        }

        return cnt;
    }
};
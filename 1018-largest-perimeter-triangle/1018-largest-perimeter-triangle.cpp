class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        sort(nums.rbegin(), nums.rend());
        int i = 0, j = 1, k = 2;

        while(i < n - 2 && j < n - 1 && k < n && i < j && j < k){
            if(nums[j] + nums[k] > nums[i]){
                return nums[i] + nums[j] + nums[k];
            }
            else{
                i++;
                j++;
                k++;
            }
        }

        return 0;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int idx1 = 0;
        int idx2 = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                res[idx1] = nums[i];
                idx1 += 2;
            }
            else{
                res[idx2] = nums[i];
                idx2 += 2;
            }
        }

        return res;
    }
};
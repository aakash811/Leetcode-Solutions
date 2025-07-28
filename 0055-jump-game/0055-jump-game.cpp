class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;

        for(int i = 0; i < n - 1; i++){
            reach = max(reach, i + nums[i]);
            if(i >= reach){
                return false;
            }
        }
        return true;
    }
};
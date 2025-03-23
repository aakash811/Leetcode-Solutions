class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int xory = 0;
       for(int i = 0; i < nums.size(); i++){
        xory ^= nums[i];
       } 
       return xory;
    }
};
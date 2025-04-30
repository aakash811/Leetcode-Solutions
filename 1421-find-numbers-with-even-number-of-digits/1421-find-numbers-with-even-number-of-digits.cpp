class Solution {
public:
    int numDig(int nums){
        int cnt = 0;
        while(nums > 0){
            cnt++;
            nums /= 10;
        }
        return cnt;
    }

    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            int cnt = numDig(nums[i]);
            res += cnt % 2 == 0 ? 1 : 0;
        }
        return res;
    }
};
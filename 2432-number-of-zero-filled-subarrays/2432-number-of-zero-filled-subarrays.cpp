class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long cnt = 0;
        long long res = 0 ;
        for(long long i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                res += (1LL * (cnt) * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        res += (1LL * (cnt) * (cnt + 1)) / 2;

        return res;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size();
        if(n < 3){
            return 0;
        }

        vector<int>preMax(n, 0), sufMax(n, 0);
        preMax[0] = nums[0];
        for(long long i = 1; i < n; i++){
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        sufMax[n - 1] = nums[n - 1];
        for(long long i = n - 2; i >= 0; i--){
            sufMax[i] = max(sufMax[i + 1], nums[i]);
        }

        long long res = 0;
        for(long long i = 1; i < n - 1; i++){
            long long x = nums[i];
            long long y = preMax[i - 1];
            long long z = sufMax[i + 1];
            long long ans = (y - x) * z;
            res = max(ans, res);
        }

        return res;
    }
};
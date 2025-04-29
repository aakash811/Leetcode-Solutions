class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int lft = 0;
        int rght = 0;
        int cnt = 0 ;
        long long subCnt = 0;
        while(rght < n){
            if(nums[rght] == maxi){
                cnt++;
            }
            while(cnt >= k){
                if(nums[lft] == maxi){
                    cnt--;
                }
                lft++;
                subCnt += 1LL * (n - rght);
            }
            rght++;
        }
        return subCnt;
    }
};
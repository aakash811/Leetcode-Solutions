class Solution {
public:
    int solve(vector<int>& vec, int mid){
        int n = vec.size();
        int cnt = 1;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(sum + vec[i] <= mid){
                sum += vec[i];
            }
            else{
                cnt++;
                sum = vec[i];
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(solve(nums, mid) > k){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
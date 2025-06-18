class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int sz = n / 3;
        vector<vector<int>>vec(sz, vector<int>(3, 0));

        int idx = 0;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < 3; j++){
                vec[i][j] = nums[idx];
                idx++;
            }
        }

        for(int i = 0; i < sz; i++){
            int diff1 = vec[i][1] - vec[i][0];
            int diff2 = vec[i][2] - vec[i][1];
            int diff3 = vec[i][2] - vec[i][0];

            if(diff1 <= k && diff2 <= k && diff3 <= k){
                continue;
            }
            else{
                return {};
            }
        }

        return vec;
    }
};
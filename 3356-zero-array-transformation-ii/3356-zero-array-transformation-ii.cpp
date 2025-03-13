class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int>vec(n + 1);

        for(int i = 0; i < n; i++)
        {
            while(sum + vec[i] < nums[i]){
                k++;

                if(k > queries.size()){
                    return -1;
                }

                int lo = queries[k - 1][0];
                int hi = queries[k - 1][1];
                int val = queries[k - 1][2];

                if(i <= hi)
                {
                    vec[max(lo, i)] += val;
                    vec[hi + 1] -= val;
                }
            }
            sum += vec[i];
        }
        return k;
    }
};
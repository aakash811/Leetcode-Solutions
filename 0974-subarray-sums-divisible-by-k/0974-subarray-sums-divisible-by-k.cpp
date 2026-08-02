class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>ump;
        int cnt = 0;
        int sum = 0;
        ump[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            // cout<<"sum-> "<<sum<<" ";
            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            // cout<<"rem-> "<<rem<<" ";

            int freq = ump[rem];
            // cout<<"freq-> "<<freq<<" ";

            cnt += freq;
            // cout<<"cnt-> "<<cnt<<" ";
            // cout<<endl;

            ump[rem]++;
        }

        return cnt;
    }
};
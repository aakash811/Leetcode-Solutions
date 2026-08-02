class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>ump;
        int zero = 0;
        int one = 0;
        int diff = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero++;
            }
            if(nums[i] == 1){
                one++;
            }
            diff = one - zero;
            if(diff == 0){
                maxLen = max(maxLen, i + 1);
            }
            else{
                if(ump.find(diff) != ump.end()){
                    maxLen = max(maxLen, i - ump[diff]);
                }
                else{
                    ump[diff] = i;
                }
            }
        }

        return maxLen;
    }
};
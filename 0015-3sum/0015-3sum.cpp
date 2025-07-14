class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        set<vector<int>>uset;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[j] + nums[k]; 
                int target = -1 * nums[i];
                
                if(sum - target > 0){
                    k--;
                }
                else if(sum - target < 0){
                    j++;
                }
                else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    uset.insert(temp);
                    j++;
                    k--;
                }
            }
        }

        for(auto it : uset){
            res.push_back(it);
        }

        return res;
    }
};
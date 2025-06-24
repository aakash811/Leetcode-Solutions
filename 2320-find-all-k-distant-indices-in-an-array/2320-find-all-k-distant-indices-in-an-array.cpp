class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>idx;
        vector<int>res;

        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                idx.push_back(i);
            }
        }

        unordered_set<int>uset;
        for(int i = 0; i < idx.size(); i++){
            int num1 = idx[i] - k;
            int num2 = idx[i] + k;
            
            num1 = max(idx[i] - k, 0);
            num2 = min(idx[i] + k, n - 1);

            for(int j = num1; j <= num2; j++){
                uset.insert(j);
            }
        }

        for(auto it : uset){
            res.push_back(it);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
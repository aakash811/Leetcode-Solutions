class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>ump;

        for(int i = 0; i < n; i++){
            ump[nums[i]]++;
        }

        vector<int>res;
        for(auto it : ump){
            if(it.second == 2){
                res.push_back(it.first);
            }
        }

        return res;
    }
};
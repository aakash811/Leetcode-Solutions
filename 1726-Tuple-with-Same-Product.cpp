class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mult = nums[i] * nums[j];
                res += ump[mult] * 8; 
                ump[mult]++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007;
        unordered_map<int, int> ump;
        ump[0] = 1; 
        int preSum = 0;
        int result = 0;

        for (int num : arr) {
            preSum += num;
            if (preSum % 2 == 1) {
                result = (result + ump[0]) % MOD;
            } else {
                result = (result + ump[1]) % MOD;
            }
            ump[preSum % 2]++;
        }

        return result;
    }
};
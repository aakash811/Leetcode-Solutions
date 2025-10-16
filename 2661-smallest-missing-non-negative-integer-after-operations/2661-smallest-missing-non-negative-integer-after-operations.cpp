class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> ump(value, 0);

        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            ump[rem]++;
        }

        int MEX = 0;
        while (ump[MEX % value] > 0) {
            ump[MEX % value]--;
            MEX++;
        }

        return MEX;
    }
};
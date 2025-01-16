class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int e1 : nums1) {
            xor1 ^= e1;
        }
        for (int e2 : nums2) {
            xor2 ^= e2;
        }
        int result = 0;
        if (nums2.size() % 2 == 1) result ^= xor1;
        if (nums1.size() % 2 == 1) result ^= xor2;
        return result;
    }
};
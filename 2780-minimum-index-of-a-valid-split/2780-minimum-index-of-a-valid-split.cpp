class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> ump;
        int dom = -1, freq = 0;

        for (int num : nums) {
            ump[num]++;
            if (ump[num] > freq) {
                freq = ump[num];
                dom = num;
            }
        }

        if (freq * 2 <= n) return -1; 

        int lCnt = 0, tot = ump[dom];

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dom) lCnt++;

            int rCnt = tot - lCnt;
            if (lCnt * 2 > (i + 1) && rCnt * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};

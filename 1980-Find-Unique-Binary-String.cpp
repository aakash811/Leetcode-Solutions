class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";

        for (int i = 0; i < nums.size(); i++) {
            char ch = nums[i][i];
            char ch1 = (ch == '0') ? '1' : '0';
            ans += ch1;
        }

        return ans;
    }
};
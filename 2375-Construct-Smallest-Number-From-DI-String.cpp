class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result = "";
        vector<int>stack(n + 1);
        int idx = 0;

        for (int i = 0; i <= n; i++) {
            stack[idx++] = i + 1;

            if (i == n || pattern[i] == 'I') {
                while (idx > 0) {
                    result += to_string(stack[--idx]);
                }
            }
        }

        return result;
    }
};
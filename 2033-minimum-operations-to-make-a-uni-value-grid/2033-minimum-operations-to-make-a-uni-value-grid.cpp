class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        for (const auto& it : grid) {
            for (int jt : it) {
                vec.push_back(jt);
            }
        }

        sort(vec.begin(), vec.end());

        for (int it : vec) {
            if (abs(it - vec[0]) % x != 0) {
                return -1;
            }
        }

        int med = vec[vec.size() / 2];
        int ops = 0;

        for (int it : vec) {
            ops += abs(it - med) / x;
        }

        return ops;
    }
};
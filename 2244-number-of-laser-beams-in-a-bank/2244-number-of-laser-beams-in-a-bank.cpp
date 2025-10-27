class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vec(bank.size(), 0);
        if (bank.empty()) return 0;

        int row = 0;
        for (auto it : bank) {
            int count = 0;
            for (int i = 0; i < bank[0].length(); i++) {
                if (it[i] == '1') count++;
            }
            vec[row++] = count;
        }

        vector<int> res;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != 0) res.push_back(vec[i]);
        }

        int ans = 0;
        if (res.size() <= 1) return ans;

        for (int i = 0; i < res.size() - 1; i++) {
            ans += res[i] * res[i + 1];
        }

        return ans;
    }
};
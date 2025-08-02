class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;

        for (int num : basket1) count[num]++;
        for (int num : basket2) count[num]--;

        vector<int> excess;
        int global_min = INT_MAX;

        for (auto& [num, freq] : count) {
            if (freq % 2 != 0) return -1;

            int times = abs(freq) / 2;
            for (int i = 0; i < times; i++) {
                excess.push_back(num);
            }

            global_min = min(global_min, num);
        }

        sort(excess.begin(), excess.end());
        long long cost = 0;
        int half = excess.size() / 2;
        for (int i = 0; i < half; i++) {
            cost += min(excess[i], 2 * global_min);
        }

        return cost;
    }
};

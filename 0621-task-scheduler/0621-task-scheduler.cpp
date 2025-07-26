class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> pq;
        for (auto& it : freq) {
            pq.push(it.second);
        }

        queue<pair<int, int>> cooldown;  

        int time = 0;
        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                if (cnt - 1 > 0) {
                    cooldown.push({time + n + 1, cnt - 1}); 
                }
            }
        }

        return time;
    }
};

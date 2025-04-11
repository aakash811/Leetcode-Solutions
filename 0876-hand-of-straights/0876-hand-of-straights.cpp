class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [num, count] : freq) {
            minHeap.push(num);
        }

        while (!minHeap.empty()) {
            int first = minHeap.top(); 

            for (int i = 0; i < groupSize; ++i) {
                int curr = first + i;

                if (freq[curr] == 0) return false;

                freq[curr]--;
                if (freq[curr] == 0 && curr == minHeap.top()) {
                    minHeap.pop();
                }
            }

            while (!minHeap.empty() && freq[minHeap.top()] == 0) {
                minHeap.pop();
            }
        }

        return true;
    }
};

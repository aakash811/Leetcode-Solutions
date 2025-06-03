class Solution {
public:
    int maxCandies(vector<int>& vis, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool flag = true;
        int res = 0;
        while (!initialBoxes.empty() && flag) {
            flag = false;
            vector<int> nxtB;
            for (int boxId : initialBoxes) {
                if (vis[boxId]) {
                    flag = true;
                    nxtB.insert(end(nxtB), begin(containedBoxes[boxId]), end(containedBoxes[boxId]));
                    for (int keyId : keys[boxId]) vis[keyId] = 1;
                    res += candies[boxId];
                } else {
                    nxtB.push_back(boxId);
                }
            }
            swap(initialBoxes, nxtB);
        }
        return res;
    }
};
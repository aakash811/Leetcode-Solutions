class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>ump;

        for(int i = 0; i < n; i++){
            ump[nums[i]]++;
        }

        priority_queue<pair<int, int>>pq;
        for(auto it : ump){
            pq.push({it.second, it.first});
        }

        vector<int>res;
        while(!pq.empty() && k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
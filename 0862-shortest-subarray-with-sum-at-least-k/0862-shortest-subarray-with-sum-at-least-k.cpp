class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>prefixHeap;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= k){
                minLen = min(minLen, i + 1);
            }

            while(!prefixHeap.empty() && prefixHeap.top().first <= sum - k){
                minLen = min(minLen, i - prefixHeap.top().second);
                prefixHeap.pop();
            }

            prefixHeap.emplace(sum, i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = INT_MAX;

        deque<int>dq;
        vector<int>prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }

        for(int i = 0; i < n; i++){
            if(prefix[i] >= k){
                minLen = min(minLen, i + 1);
            }

            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[i] <= prefix[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
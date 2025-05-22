class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> maxH;
        priority_queue<int, vector<int>, greater<int>> minH;
        int count = 0;

        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (!minH.empty() && minH.top() < i){
                minH.pop();
            }

            while (j < queries.size() && queries[j][0] <= i){
                maxH.push(queries[j++][1]);
            } 

            while (minH.size() < nums[i] && !maxH.empty() && maxH.top() >= i) {
                minH.push(maxH.top());
                maxH.pop();
                count++;
            }

            if (minH.size() < nums[i]){
                return -1;
            }
        }
        return queries.size() - count;
    }
};
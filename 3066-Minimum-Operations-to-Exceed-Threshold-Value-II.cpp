class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int , vector<long long int>, greater<long long int>> pqr;

        for(long long int i = 0; i < nums.size(); i++)
        {
            pqr.push(nums[i]);
        }

        long long int cnt = 0;
        while(pqr.top() < k)
        {
            long long int x = pqr.top();
            pqr.pop();
            long long int y = pqr.top();
            pqr.pop();

            long long ele = 2 * min(x, y) + max(x, y);
            pqr.push(ele);
            cnt++;
        }

        return cnt;
    }
};
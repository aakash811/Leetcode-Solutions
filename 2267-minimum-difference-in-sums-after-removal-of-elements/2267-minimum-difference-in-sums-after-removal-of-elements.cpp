class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int total = 3 * n;

        priority_queue<int> leftHeap;
        vector<long long> leftSum(total, 0);
        long long sum = 0;

        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            leftHeap.push(nums[i]);

            if (leftHeap.size() > n) {
                sum -= leftHeap.top();
                leftHeap.pop();
            }

            if (leftHeap.size() == n) {
                leftSum[i] = sum;
            }
        }

        priority_queue<int, vector<int>, greater<int>> rightHeap;
        vector<long long> rightSum(total, 0);
        sum = 0;

        for (int i = total - 1; i >= n; i--) {
            sum += nums[i];
            rightHeap.push(nums[i]);

            if (rightHeap.size() > n) {
                sum -= rightHeap.top();
                rightHeap.pop();
            }

            if (rightHeap.size() == n) {
                rightSum[i] = sum;
            }
        }

        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            res = min(res, leftSum[i] - rightSum[i + 1]);
        }

        return res;
    }
};

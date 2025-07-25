class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>stk1;
        stack<int>stk2;
        vector<int>lft(n), rght(n);

        for(int i = 0; i < n; i++){
            while(!stk1.empty() && arr[stk1.top()] > arr[i]){
                stk1.pop();
            }
            lft[i] = stk1.empty() ? -1 : stk1.top();
            stk1.push(i);
        }

        for(int i = n - 1; i >= 0; i--){
            while(!stk2.empty() && arr[stk2.top()] >= arr[i]){
                stk2.pop();
            }
            rght[i] = stk2.empty() ? n : stk2.top();
            stk2.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++){
            int lftSum = i - lft[i];
            int rghtSum = rght[i] - i;

            long long sum = (arr[i] * lftSum * rghtSum) % MOD;
            res = (res + sum) % MOD;
        }
        return res;
    }
};
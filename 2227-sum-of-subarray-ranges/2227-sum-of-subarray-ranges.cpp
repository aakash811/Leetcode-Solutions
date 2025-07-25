class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk1, stk2, stk3, stk4;
        vector<int> lftMin(n), rghtMin(n), lftMax(n), rghtMax(n);

        for(int i = 0; i < n; i++){
            while(!stk1.empty() && nums[stk1.top()] > nums[i]){
                stk1.pop();
            }
            lftMin[i] = stk1.empty() ? -1 : stk1.top();
            stk1.push(i);
        }

        for(int i = n - 1; i >= 0; i--){
            while(!stk2.empty() && nums[stk2.top()] >= nums[i]){
                stk2.pop();
            }
            rghtMin[i] = stk2.empty() ? n : stk2.top();
            stk2.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!stk3.empty() && nums[stk3.top()] < nums[i]){
                stk3.pop();
            }
            lftMax[i] = stk3.empty() ? -1 : stk3.top();
            stk3.push(i);
        }

        for(int i = n - 1; i >= 0; i--){
            while(!stk4.empty() && nums[stk4.top()] <= nums[i]){
                stk4.pop();
            }
            rghtMax[i] = stk4.empty() ? n : stk4.top();
            stk4.push(i);
        }

        long long cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            long long x = i - lftMin[i];
            long long y = rghtMin[i] - i;
            long long x1 = lftMax[i] - i;
            long long y1 = i - rghtMax[i];

            long long sum1 = x * y * nums[i];
            long long sum2 = x1 * y1 * nums[i];
            cnt1 += sum1;
            cnt2 += sum2;
        }
        return abs(cnt1 - cnt2);
    }
};
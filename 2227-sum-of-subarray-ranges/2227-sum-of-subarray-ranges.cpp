class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>lftMin(n), rghtMin(n), lftMax(n), rghtMax(n);
        stack<long long>stk1;
        stack<long long>stk2;
        stack<long long>stk3;
        stack<long long>stk4;

        for(long long i = 0; i < n; i++){
            while(!stk1.empty() && nums[stk1.top()] > nums[i]){
                stk1.pop();
            }
            lftMin[i] = stk1.empty() ? -1 : stk1.top();
            stk1.push(i);
        }
        
        for(long long i = n - 1; i >= 0; i--){
            while(!stk2.empty() && nums[stk2.top()] >= nums[i]){
                stk2.pop();
            }
            rghtMin[i] = stk2.empty() ? n : stk2.top();
            stk2.push(i);
        }

        for(long long i = 0; i < n; i++){
            while(!stk3.empty() && nums[stk3.top()] < nums[i]){
                stk3.pop();
            }
            lftMax[i] = stk3.empty() ? -1 : stk3.top();
            stk3.push(i);
        }
        
        for(long long i = n - 1; i >= 0; i--){
            while(!stk4.empty() && nums[stk4.top()] <= nums[i]){
                stk4.pop();
            }
            rghtMax[i] = stk4.empty() ? n : stk4.top();
            stk4.push(i);
        }

        long long cnt1 = 0;
        long long cnt2 = 0;
        // for(int i = 0; i < n; i++){
        //     cout<<lftMin[i]<<" "<<rghtMin[i]<<endl;
        // }
        
        // for(int i = 0; i < n; i++){
        //     cout<<lftMax[i]<<" "<<rghtMax[i]<<endl;
        // }

        for(long long i = 0; i < n; i++){
            long long x = i - lftMin[i];
            long long y = rghtMin[i] - i;

            long long ans = x * y * nums[i];
            cnt1 += ans;
        }

        for(long long i = 0; i < n; i++){
            long long x = lftMax[i] - i;
            long long y = i - rghtMax[i];

            long long ans = x * y * nums[i];
            cnt2 += ans;
        }

        return abs(cnt1 - cnt2);
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>deque;
        vector<int>res;

        for(int i = 0 ; i < n; i++){
            while(!deque.empty() && deque.back() < nums[i]){
                deque.pop_back();
            }
            deque.push_back(nums[i]);

            if(i >= k && nums[i - k] == deque.front()){
                deque.pop_front();
            }

            if(i >= k - 1){
                res.push_back(deque.front());
            }
        }

        return res;
    }
};
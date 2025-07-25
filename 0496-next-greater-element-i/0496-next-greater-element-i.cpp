class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int, int>ump;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && nums2[i] >= stk.top()){
                stk.pop();
            }
            ump[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int>res;
        for(int i = 0; i < nums1.size(); i++){
            res.push_back(ump[nums1[i]]);
        }
        return res;
    }
};
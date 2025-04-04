class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        map<int, int> mpp;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            mpp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        n = nums1.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            res.push_back(mpp[nums1[i]]);
        }
        return res;
    }
};
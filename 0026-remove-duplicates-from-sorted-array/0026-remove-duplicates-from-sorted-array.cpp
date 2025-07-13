class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;

        for(auto it : nums){
            st.insert(it);
        }
        vector<int>v(st.begin(), st.end());
        nums= v;
        return st.size();
    }
};
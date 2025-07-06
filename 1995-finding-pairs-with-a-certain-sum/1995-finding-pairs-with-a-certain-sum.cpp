class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int>ump;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto it : nums2){
            ump[it]++;
        }
    }
    
    void add(int index, int val) {
        ump[nums2[index]]--;
        nums2[index] += val;
        ump[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto it : nums1){
            int diff = tot - it;
            if(ump.count(diff)){
                res += ump[diff];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
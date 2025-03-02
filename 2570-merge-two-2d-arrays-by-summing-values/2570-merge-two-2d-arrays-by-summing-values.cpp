class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int>ump;

        for(int i = 0; i < n; i++){
            ump[nums1[i][0]] = nums1[i][1];
        }

        for(int i = 0; i < m; i++){
            ump[nums2[i][0]] += nums2[i][1];
        }

        vector<vector<int>>vec;

        for(auto it : ump){
            vec.push_back({it.first, it.second});
        }
        sort(vec.begin(), vec.end());
        return vec;
    }
};
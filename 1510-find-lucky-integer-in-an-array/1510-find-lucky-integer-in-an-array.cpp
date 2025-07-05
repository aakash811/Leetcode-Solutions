class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>ump;
        for(auto it : arr){
            ump[it]++;
        }
        int res = -1;
        for(auto it : ump){
            if(it.second == it.first){
                res = max(res, it.first);
            }
        }

        return res;
    }
};
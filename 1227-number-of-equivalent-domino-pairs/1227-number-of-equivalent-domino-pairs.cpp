class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> mpp;
            int count = 0;
            for(auto it : dominoes){
                if(it[0] > it[1]) swap(it[0], it[1]);
                count += mpp[{it[0], it[1]}]++;
            }
            return count;
        }
    };
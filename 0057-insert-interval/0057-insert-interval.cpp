class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>res;
        int st = newInterval[0];
        int en = newInterval[1];
        bool flag = false;

        for(int i = 0; i < n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];

            if(st > y || flag){
                res.push_back({x, y});
                continue;
            }
            st = min(st, x);
            if(en < x){
                res.push_back({st, en});
                res.push_back({x, y});
                flag = true;
                continue;
            }
            if(en <= y){
                res.push_back({st, y});
                flag = true;
                continue;
            }
        }

        if(!flag){
            res.push_back({st, en});
        }
        return res;
    }
};
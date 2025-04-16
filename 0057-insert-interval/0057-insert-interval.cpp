class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int st = newInterval[0];
        int end = newInterval[1];
        bool flag = false;
        vector<vector<int>>res;

        for(int i = 0; i < n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];

            if(y < st || flag){
                res.push_back({x, y});
                continue;
            }
            st = min(st, x);
            if(x > end){
                res.push_back({st, end});
                res.push_back({x, y});
                flag = true;
                continue;
            }
            if(end <= y){
                res.push_back({st, y});
                flag = true;
            }
        }
        if(!flag){
            res.push_back({st, end});
        }

        return res;
    }
};
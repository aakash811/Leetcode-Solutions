class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        bool flag = false;

        vector<vector<int>>res;
        for(int i = 0; i < n; i++){
            int intervalStart = intervals[i][0];
            int intervalEnd = intervals[i][1];

            if(intervalEnd < start || flag){
                res.push_back({intervalStart, intervalEnd});
                continue;
            }
            start = min(start, intervalStart);
            if(intervalStart > end){
                res.push_back({start, end});
                res.push_back({intervalStart, intervalEnd});
                flag = true;
                continue;
            }
            else if(intervalEnd >= end){
                res.push_back({start, intervalEnd});
                flag = true;
                continue;
            }
        }

        if(!flag){
            res.push_back({start, end});
        }
        return res;
    }
};
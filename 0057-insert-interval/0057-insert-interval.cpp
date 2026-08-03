class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            return {newInterval};
        }
        sort(intervals.begin(), intervals.end());

       vector<vector<int>>merged;
       bool done = false;

       if(intervals[0][0] > newInterval[0]){
        merged.push_back(newInterval);
        done = true;
       }
       else{
        merged.push_back(intervals[0]);
       }

       for(int i = 0; i < n; i++){
        if(!done && i == 0){
            continue;
        }
        vector<int>& currentInterval = merged.back();
        vector<int> nextInterval = intervals[i];

        if(!done && nextInterval[0] > newInterval[0]){
            if(currentInterval[1] >= newInterval[0]){
                currentInterval[1] = max(currentInterval[1], newInterval[1]);
            }
            else{
                merged.push_back(newInterval);
            }
            done = true;
        }
        
        vector<int>& currInterval = merged.back();
        if(currInterval[1] >= nextInterval[0]){
            currInterval[1] = max(currInterval[1], nextInterval[1]);
        }
        else{
            merged.push_back(nextInterval);
        }
       }

       if(!done){
        if(merged.back()[1] >= newInterval[0]){
            merged.back()[1] = max(merged.back()[1], newInterval[1]);
        }
        else{
            merged.push_back(newInterval);
        }
       }

       return merged;
    }
};
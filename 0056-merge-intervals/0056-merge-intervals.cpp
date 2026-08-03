class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>merged;
        merged.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            vector<int>& currInterval = merged.back();
            vector<int> nextInterval = intervals[i];

            // cout<<"CurrInterval-> "<<currInterval[0]<<" "<<currInterval[1]<<endl;
            // cout<<"NextInterval-> "<<nextInterval[0]<<" "<<nextInterval[1]<<endl;
            // cout<<"MaxEnd-> "<<max(currInterval[1], nextInterval[1])<<endl;

            if(currInterval[1] >= nextInterval[0]){
                currInterval[1] = max(currInterval[1], nextInterval[1]);
                // cout<<"CurrInterval after maxEnd-> "<<currInterval[0]<<" "<<currInterval[1]<<endl;
            }
            else{
                merged.push_back(nextInterval);
            }
        }

        return merged;
    }
};
class Solution {
public:
    vector<vector<int>> revGraph(vector<vector<int>>& graph){
        int n = graph.size();
        vector<vector<int>>revG(n);

        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                revG[it].push_back(i);
            }
        }

        return revG;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indeg(n, 0);
        vector<vector<int>>revG = revGraph(graph);

        for(int i = 0; i < n; i++){
            for(auto it : revG[i]){
                indeg[it]++;
            }
        }

        queue<int>q;
        vector<int>topo;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : revG[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
    }
};
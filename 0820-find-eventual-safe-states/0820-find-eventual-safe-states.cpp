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
        vector<int>inDegree(n);
        vector<vector<int>>revG = revGraph(graph);

        for(int i = 0; i < n; i++){
            for(auto it : revG[i]){
                inDegree[it]++;
            }
        }

        vector<int>topo;
        queue<int>q;

        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : revG[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};
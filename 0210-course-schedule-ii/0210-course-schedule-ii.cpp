class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDeg(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            inDeg[u]++;
        }

        queue<int>q;
        vector<int>topo;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};
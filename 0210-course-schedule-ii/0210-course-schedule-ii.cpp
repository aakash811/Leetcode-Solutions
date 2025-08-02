class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() != numCourses){
            return {};
        }
        return topo;
    }
};
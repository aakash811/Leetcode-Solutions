class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];

            adj[u].push_back({t, v});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        vector<int>dist(n + 1, 1e9);

        q.push({0, k});
        dist[k] = 0;

        while(!q.empty()){
            auto it = q.top();
            int node = it.second;
            int time = it.first;
            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.second;
                int wt = it.first;
                if(wt + time < dist[adjNode]){
                    dist[adjNode] = time + wt;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) { 
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
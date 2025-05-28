class Solution {
public:
    int bfs(int source, vector<vector<int>>& adj, int k) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        int dist = 0;
        int count = 0;

        while (!q.empty() && dist <= k) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int node = q.front(); q.pop();
                count++;
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            dist++;
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);

        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> tree2_reach(m);
        for (int i = 0; i < m; ++i) {
            tree2_reach[i] = bfs(i, adj2, k - 1);
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            int tree1_cnt = bfs(i, adj1, k);
            int max_total = 0;
            for (int j = 0; j < m; ++j) {
                max_total = max(max_total, tree1_cnt + tree2_reach[j]);
            }
            result[i] = max_total;
        }

        return result;
    }
};

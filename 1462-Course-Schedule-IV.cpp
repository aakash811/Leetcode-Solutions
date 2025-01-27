class Solution {
public:
    void topologicalSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i])
                topologicalSortUtil(i, adj, visited, st);
        }
        st.push(v);
    }

    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topologicalSortUtil(i, adj, visited, st);
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < preq.size(); i++) {
            adj[preq[i][0]].push_back(preq[i][1]);
        }

        vector<int> order = topologicalSort(adj);

        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));

        for (int i = 0; i < numCourses; i++) {
            for (int neighbor : adj[i]) {
                grid[i][neighbor] = true;
            }
        }

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (grid[i][k] && grid[k][j]) {
                        grid[i][j] = true;
                    }
                }
            }
        }

        int qs = queries.size();
        vector<bool> ans(qs);
        for (int i = 0; i < qs; i++) {
            ans[i] = grid[queries[i][0]][queries[i][1]];
        }

        return ans;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prnt, minCst;

    int findRoot(int node) {
        if (prnt[node] != node) {
            prnt[node] = findRoot(prnt[node]); 
        }
        return prnt[node];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        prnt.resize(n);
        minCst.assign(n, -1);
        for (int i = 0; i < n; i++) prnt[i] = i;

        for (auto& it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            int src = findRoot(u);
            int trg = findRoot(v);

            if (minCst[src] == -1) minCst[src] = wt;
            else minCst[src] &= wt;

            if (minCst[trg] == -1) minCst[trg] = wt;
            else minCst[trg] &= wt;

            if (src != trg) {
                prnt[src] = trg;
                minCst[trg] &= minCst[src];
            }
        }

        vector<int> res;
        for (auto& it : queries) {
            int l = it[0], r = it[1];

            if (l == r) res.push_back(0);
            else if (findRoot(l) != findRoot(r)) res.push_back(-1);
            else res.push_back(minCst[findRoot(l)]);
        }

        return res;
    }
};
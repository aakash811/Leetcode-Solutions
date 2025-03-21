class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> inDegree;

        for (int i = 0; i < recipes.size(); i++) {
            for (string it : ingredients[i]) {
                adj[it].push_back(recipes[i]);
            }
            inDegree[recipes[i]] = ingredients[i].size();
        }

        vector<string> result;
        queue<string> q;
        for (string it : supplies) {
            q.push(it);
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (string it : adj[curr]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    result.push_back(it);
                    q.push(it);
                }
            }
        }
        return result;
    }
};
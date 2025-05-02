class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<pair<int,int>, TreeNode*>> q;
        vector<vector<int>> res;

        q.push({{0, 0}, root});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;  
            int y = it.first.second;  
            TreeNode* node = it.second;

            mp[x][y].insert(node->val);

            if(node->left){
                q.push({{x - 1, y + 1}, node->left});
            }
            if(node->right){
                q.push({{x + 1, y + 1}, node->right});
            }
        }

        for(auto& it : mp){
            vector<int> ds;
            for(auto& jt : it.second){
                for(int val : jt.second){
                    ds.push_back(val);
                }
            }
            res.push_back(ds);
        }

        return res;
    }
};

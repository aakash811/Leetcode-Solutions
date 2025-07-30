/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        queue<pair<pair<int, int>, TreeNode*>>q;

        q.push({{0, 0}, root});

        while(!q.empty()){
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

        vector<vector<int>>res;
        for(auto it : mp){
            vector<int>ds;
            for(auto jt : it.second){
                for(auto kt : jt.second){
                    ds.push_back(kt);
                }
            }
            res.push_back(ds);
        }
        return res;
    }
};
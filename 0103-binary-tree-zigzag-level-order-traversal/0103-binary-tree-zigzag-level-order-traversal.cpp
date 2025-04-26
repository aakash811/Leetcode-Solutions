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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        int idx = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<int>ds;
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                ds.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            if(idx % 2 == 1){
                reverse(ds.begin(), ds.end());
            }
            res.push_back(ds);
            idx++;
        }

        return res;
    }
};
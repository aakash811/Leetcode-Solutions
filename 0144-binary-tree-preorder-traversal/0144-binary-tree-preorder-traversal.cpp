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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        stack<TreeNode*>stk;
        vector<int>res;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();

            res.push_back(node->val);

            if(node->right){
                stk.push(node->right);
            }
            if(node->left){
                stk.push(node->left);
            }
        }
        return res;
    }
};
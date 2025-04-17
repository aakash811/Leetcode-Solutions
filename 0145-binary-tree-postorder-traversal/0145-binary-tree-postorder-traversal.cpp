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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int>vec;
        stack<TreeNode*>stk;
        TreeNode* cur = root;

        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            while(cur){
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            vec.push_back(cur->val);
        }
        return vec;
    }
};
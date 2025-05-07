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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode();
            root->val = val;
            return root;
        }
        
        if(root->val < val){
            if(root->right){
                insertIntoBST(root->right, val);
            }
            else{
                root->right = new TreeNode();
                root->right->val = val;
                return root;
            }
        }
        else{
            if(root->left){
                insertIntoBST(root->left, val);
            }
            else{
                root->left = new TreeNode();
                root->left->val = val;
                return root;
            }
        }
        return root;
    }
};
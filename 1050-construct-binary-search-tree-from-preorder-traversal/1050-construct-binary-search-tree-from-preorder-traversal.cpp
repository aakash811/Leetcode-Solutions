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
    TreeNode* solve(int& idx, vector<int>& preorder, int upperB){
        if(idx == preorder.size() || preorder[idx] > upperB){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = solve(idx, preorder, root->val);
        root->right = solve(idx, preorder, upperB);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0 ;
        return solve(idx, preorder, INT_MAX);
    }
};
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
    int solve(TreeNode* root, int path, int& maxi){
        if(!root){
            return 0;
        }
        
        int lPath = max (0, solve(root -> left, path + root -> val, maxi));
        int rPath = max(0, solve(root -> right, path + root -> val, maxi));
        maxi = max(lPath + rPath + root -> val, maxi);

        return max(lPath, rPath) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxi = root -> val;
        solve(root, 0, maxi);
        return maxi;
    }
};
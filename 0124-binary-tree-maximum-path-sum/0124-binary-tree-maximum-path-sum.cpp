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
    int solve(TreeNode* root, int& maxi, int path){
        if(!root){
            return 0;
        }

        int lMax = max(0, solve(root->left, maxi, path + root->val));
        int rMax = max(0, solve(root->right, maxi, path + root->val));
        maxi = max(maxi, lMax + rMax + root->val);

        return max(lMax, rMax) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxi = root->val;
        solve(root, maxi, 0);
        return maxi;
    }
};
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
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }

        int lft = solve(root->left);
        if(lft == -1){
            return -1;
        }

        int rght = solve(root->right);
        if(rght == -1){
            return -1;
        }

        if(abs(lft - rght) > 1){
            return -1;
        }

        return 1 + max(lft, rght);
    }

    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        return solve(root) != -1;
    }
};
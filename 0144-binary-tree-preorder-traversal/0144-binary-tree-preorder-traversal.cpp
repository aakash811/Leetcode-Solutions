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
        if (root==NULL) return {};
        vector <int>result;
        result.push_back(root->val);
        vector<int>left=preorderTraversal(root->left);
        vector<int>right=preorderTraversal(root->right);
        for (int it:left){
            result.push_back(it);
        }
         for (int it:right){
            result.push_back(it);
        }
        return result;
        
    }
};
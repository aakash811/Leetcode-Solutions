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
    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, map<int, int>& mp){
        if(inStart > inEnd || preStart > preEnd){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);
        int idx = mp[node->val];
        int numsLeft = idx - inStart;

        node->left = solve(inorder, inStart, idx - 1, preorder, preStart + 1, preEnd + numsLeft, mp);
        node->right = solve(inorder, idx + 1, inEnd, preorder, preStart + numsLeft + 1, preEnd, mp);

        return node; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, mp);
    }
};
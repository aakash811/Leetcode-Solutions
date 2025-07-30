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

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& preOrder, int preStart, int preEnd, map<int,int>& m)
    {
        if(inStart > inEnd || preStart > preEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preOrder[preStart]);

        int idx = m[root->val];
        int numsLeft = idx - inStart;

        root->left = buildTree(inorder, inStart, idx - 1, preOrder, preStart + 1, preStart + numsLeft, m);
        root->right = buildTree(inorder, idx + 1, inEnd, preOrder, preStart + numsLeft + 1, preEnd, m);

        return root; 
    }

    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inorder) {
        map<int,int> m;

        for(int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, preOrder, 0, preOrder.size() - 1, m);
        return root;
    }
};
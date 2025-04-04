class Solution {
public:
    int maxDepth = 0;
    TreeNode* lca = NULL;

    int dfs(TreeNode* root, int depth) {
        if (!root) return depth - 1;

        maxDepth = max(maxDepth, depth);

        int leftDepth = dfs(root->left, depth + 1);
        int rightDepth = dfs(root->right, depth + 1);

        if (leftDepth == maxDepth && rightDepth == maxDepth) {
            lca = root;
        }

        return max(leftDepth, rightDepth); 
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return lca;
    }
};

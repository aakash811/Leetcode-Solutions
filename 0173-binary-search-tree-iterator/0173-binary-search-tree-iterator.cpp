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
class BSTIterator {
public:
    vector<int>inorder;
    void solve(TreeNode* root, vector<int>& inorder){
       if(root != nullptr){
            solve(root->left, inorder);
            inorder.push_back(root->val);
            solve(root->right, inorder);
        }
    }
    BSTIterator(TreeNode* root) {
        solve(root, inorder);
    }
    
    int idx = 0;
    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        if(idx < inorder.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
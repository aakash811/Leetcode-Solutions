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
    bool isPali(const vector<int>& vec){
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            if (vec[i] != vec[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> vec;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    vec.push_back(node->val);
                    q.push(node->left);   
                    q.push(node->right);
                } else {
                    vec.push_back(-101);  
                }
            }
            
            if (!isPali(vec)) {
                return false;
            }
        }

        return true;
    }
};

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
    void solve(TreeNode* root, vector<int>& vec){
        if(root != NULL){
            solve(root->left, vec);
            vec.push_back(root->val);
            solve(root->right, vec);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>vec;
        solve(root, vec);
        int j = vec.size() - 1;
        int i = 0;

        while(i < j){
            if(vec[i] + vec[j] < k){
                i++;
            }
            else if(vec[i] + vec[j] > k){
                j--;
            }
            else if(vec[i] + vec[j] == k){
                return true;
            }
        }
        return false;
    }
};
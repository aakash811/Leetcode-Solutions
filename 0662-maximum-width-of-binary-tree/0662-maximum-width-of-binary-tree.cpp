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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});

        long long int maxW = 0;
        while(!q.empty()){
            int sz = q.size();
            long long int lft = 0, rght = 0;
            for(int i = 0; i < sz; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int pos = it.second;

                if(i == 0){
                    lft = pos;
                }
                if(i == sz - 1){
                    rght = pos;
                }

                if(node->left){
                    q.push({node->left, 1LL * 2 * pos + 1});
                }

                if(node->right){
                    q.push({node->right, 1LL * 2 * pos + 2});
                }
            }
            maxW = max(maxW, rght - lft + 1);
        }

        return maxW;
    }
};
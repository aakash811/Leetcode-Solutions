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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        
        vector<vector<int>>res;
        queue<TreeNode*>q;

        q.push(root);
        int k = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(k % 2 != 0){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            k++;
        }
        return res;
    }
};
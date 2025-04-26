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
    void solve(queue<TreeNode*>& q, TreeNode* root, vector<int>& vec){        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    vec.push_back(node->val);
                }
                else{
                    vec.push_back(-1e5);
                    continue;
                }
                
                if(node->left){
                    q.push(node->left);
                }
                if(!node->left){
                    q.push(nullptr);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(!node->right){
                    q.push(nullptr);
                }
            }
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>vec1;
        vector<int>vec2;

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);

        solve(q1, p, vec1);
        solve(q2, q, vec2);

        return vec1 == vec2;
    }
};
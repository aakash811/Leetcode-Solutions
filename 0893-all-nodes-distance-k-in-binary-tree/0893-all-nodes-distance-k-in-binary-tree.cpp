/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findPrnt(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& prnt){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                prnt[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                prnt[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>prnt;
        unordered_map<TreeNode*, bool>vis;
        findPrnt(root, prnt);

        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int dis = 0;

        while(!q.empty()){
            int sz = q.size();
            if(dis++ == k){
                break;
            }

            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(prnt[node] && !vis[prnt[node]]){
                    q.push(prnt[node]);
                    vis[prnt[node]] = true;
                }
            }
        }

        vector<int>res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;
    }
};
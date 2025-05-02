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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if (root == nullptr) {
            return vec; 
        }

        queue<pair<TreeNode*, int>>q;
        map<int,int>m;
        q.push({root,0});

        while(!q.empty())
        {
            auto it = q.front();
            int y = it.second;
            q.pop();
            m[y] = it.first -> val;

            if(it.first -> left)
            {
                q.push({it.first->left,y+1});
            }
            if(it.first -> right)
            {
                q.push({it.first->right,y+1});
            }
        }

        for(auto it : m)
        {
            vec.push_back(it.second);
        }

        return vec;
    }
};
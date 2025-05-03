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

    string s = "";
    void func(TreeNode* root, vector<string>& vec)
    {
        string val = to_string(root->val);
        s += val;

        if(root->left == NULL && root->right ==NULL)
        {
            vec.push_back(s);
            s = s.substr(0, s.size()-val.size()-2);
            return;
        }
        
        if(root->left)
        {
            s +="->";
            func(root->left, vec);
        }
        if(root->right)
        {
            s +="->";
            func(root->right,vec);
        }
         s = s.substr(0, s.size()-val.size()-2);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>vec;
        if(root == NULL)
        {
            return vec;
        }
        func(root, vec);
        return vec;
    }
};
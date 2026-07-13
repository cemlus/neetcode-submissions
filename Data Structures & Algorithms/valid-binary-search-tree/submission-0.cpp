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
    bool recurse(TreeNode* root, int mini, int maxi){
        if(!root) return true;

        if(root->val <= mini || root->val >= maxi){
            return false;
        }
        bool lefty = recurse(root->left, mini, root->val);
        bool righty = recurse(root->right, root->val, maxi);
        
        return lefty && righty;
    }

    bool isValidBST(TreeNode* root) {
        return recurse(root, INT_MIN, INT_MAX);
    }
};

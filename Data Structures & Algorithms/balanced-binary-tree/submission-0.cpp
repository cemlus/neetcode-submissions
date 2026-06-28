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
    int recurse(TreeNode* root){
        if(root == nullptr) return true;

        int leftH = recurse(root->left);
        if(leftH == -1) return -1;
        int rightH = recurse(root->right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1) return -1;

        return 1 + max(leftH, rightH);

    }

    bool isBalanced(TreeNode* root) {
        if(recurse(root) == -1) return false;
        return true;
    }
};

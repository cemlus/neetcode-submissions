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
    int dia = 0;
    int recurse(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = recurse(root->left);
        int rightH = recurse(root->right);

        dia = max(dia, leftH + rightH);

        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        recurse(root);
        return dia;
    }
};

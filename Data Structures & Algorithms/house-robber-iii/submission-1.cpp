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
    pair<int, int> recurse(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        pair<int, int> leftTree = recurse(root->left);
        pair<int, int> rightTree = recurse(root->right);

        // process the node (postorder traversal)
        int pickRoot = root->val + leftTree.second + rightTree.second;
        int notPickRoot =
            0 + max(leftTree.first, leftTree.second) + max(rightTree.first, rightTree.second);

        return {pickRoot, notPickRoot};
    }

    int rob(TreeNode* root) {
        if (root == nullptr) return 0;

        int pickRoot = recurse(root).first;
        int notPickRoot = recurse(root).second;

        return max(pickRoot, notPickRoot);
    }
};
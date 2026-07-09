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
    int recurse(TreeNode* root, int maxi) {
        if (root == nullptr) return 0;

        int ans = 0;
        if (root->val >= maxi) {
            ans = 1;
        } else {
            ans = 0;
        }

        maxi = max(root->val, maxi);
        ans += recurse(root->left, maxi);
        ans += recurse(root->right, maxi);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        int n = 1;
        int leftTree = recurse(root->left, root->val);
        int rightTree = recurse(root->right, root->val);
        return n + leftTree + rightTree;
    }
};

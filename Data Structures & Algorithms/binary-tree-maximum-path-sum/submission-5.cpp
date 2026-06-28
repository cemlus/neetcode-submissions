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
    int maxi = -1e4;

    int recurse(TreeNode* root) {
        // base case
        if (root == nullptr) return 0;

        // call recursion
        int leftSum = recurse(root->left);
        if(leftSum < 0) leftSum = 0;

        int rightSum = recurse(root->right);
        if(rightSum < 0) rightSum = 0;

        // maxi stores the answer
        maxi = max(leftSum + rightSum + root->val, maxi);

        // return tells the parent what CAN be extended
        return max({max(leftSum, rightSum)}) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int random = recurse(root);
        return maxi;
    }
};

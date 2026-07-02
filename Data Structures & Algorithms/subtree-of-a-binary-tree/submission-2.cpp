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

    bool recurse(TreeNode* target, TreeNode* subRoot) {
        if (target == nullptr && subRoot == nullptr) return true;
        if (!subRoot) return false;
        if (!target) return false;
        if (target->val == subRoot->val) {
            bool lefty = recurse(target->left, subRoot->left);
            bool righty = recurse(target->right, subRoot->right);

            return lefty && righty;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root != nullptr && subRoot == nullptr) return true;
        if (root == nullptr && subRoot != nullptr) return false;

        if(recurse(root, subRoot)) return true;
        
        bool isLeft = isSubtree(root->left, subRoot);
        bool isRight = isSubtree(root->right, subRoot);

        return isLeft || isRight;
    }
};

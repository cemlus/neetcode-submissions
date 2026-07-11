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
    TreeNode* getRightMost(TreeNode* root) {
        while (root && root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // key is equal to root node
            
            // if it has 0 or 1 child
            if(root->left == nullptr){
                TreeNode* rightTree = root->right;
                delete root;
                // this will automatically attach itself to the concerned parent's side
                return rightTree;
            }
            if(root->right == nullptr){
                TreeNode* leftTree = root->left;
                delete root;
                return leftTree;
            }

            // it has both children
            TreeNode* rightTree = root->right;
            TreeNode* lefty = root->left;
            TreeNode* rightMost = getRightMost(lefty);
            rightMost->right = rightTree;
            delete root;
            return lefty;
        }
        return root;
    }
};
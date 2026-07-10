/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recurse(TreeNode* root, int val) {
        if (root == nullptr)
            return;

        if (val > root->val) {
            recurse(root->right, val);
        } else {
            recurse(root->left, val);
        }

        if(root->left == nullptr && val < root->val){
            TreeNode* newNode = new TreeNode(val);
            root->left = newNode;
        }
        if(root->right == nullptr && val > root->val){
            TreeNode* newNode = new TreeNode(val);
            root->right = newNode;
        }

        if (root->left == nullptr && root->right == nullptr) {
            TreeNode* newNode = new TreeNode(val);
            if (val < root->val) {
                root->left = newNode;
            } else {
                root->right = newNode;
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        recurse(root, val);
        return root;
    }
};
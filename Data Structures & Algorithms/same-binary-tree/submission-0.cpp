/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 *     TreeNode() : val(0), right(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool recurse(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;

        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;

        if(p->val != q->val) return false;

        bool leftChild = recurse(p->left, q->left);
        bool rightChild = recurse(p->right, q->right);

        return leftChild && rightChild;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recurse(p, q);
    }
};

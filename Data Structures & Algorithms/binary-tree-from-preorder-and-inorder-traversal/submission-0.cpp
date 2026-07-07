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
    TreeNode* makeTree(vector<int>& preorder, int preOrderStart,
                       int preOrderEnd, vector<int>& inorder, int inOrderStart,
                       int inOrderEnd, map<int, int>& inMap) {
        if (preOrderStart > preOrderEnd || inOrderStart > inOrderEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preOrderStart]);

        int inOrderRoot = inMap[root->val];
        int numsLeft = inOrderRoot - inOrderStart;

        root->left =
            makeTree(preorder, preOrderStart + 1, preOrderStart + numsLeft,
                     inorder, inOrderStart, inOrderRoot - 1, inMap);
        root->right =
            makeTree(preorder, preOrderStart + numsLeft + 1, preOrderEnd,
                     inorder, inOrderRoot + 1, inOrderEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = makeTree(preorder, 0, preorder.size() - 1, inorder, 0,
                                  inorder.size() - 1, inMap);

        return root;
    }
};
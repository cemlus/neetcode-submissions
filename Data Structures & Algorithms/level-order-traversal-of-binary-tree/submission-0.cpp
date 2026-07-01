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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> curr;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> curr;
            for(int i = 0 ; i < sz ; i++){
                TreeNode* node = q.front();
                q.pop();

                curr.push_back(node->val);

                // left
                if(node->left){
                    q.push(node->left);
                }
                // right
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

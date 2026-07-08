# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if not root:
                return [0, 0]

            leftTree = dfs(root.left)
            rightTree = dfs(root.right)

            # process the node
            withRoot = root.val + leftTree[1] + rightTree[1]
            withoutRoot = 0 + max(leftTree[0], leftTree[1]) + max(rightTree[0], rightTree[1])

            return [withRoot, withoutRoot]

        [withRoot, withoutRoot] = dfs(root)
        return max(withRoot, withoutRoot)

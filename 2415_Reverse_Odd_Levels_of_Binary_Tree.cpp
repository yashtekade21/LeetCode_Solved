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
    // loved the logic of recursion
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }

private:
    void dfs(TreeNode* leftNode, TreeNode* rightNode, int level) {
        if (!leftNode || !rightNode)
            return;
        if (level % 2) {
            int temp = leftNode->val;
            leftNode->val = rightNode->val;
            rightNode->val = temp;
        }

        dfs(leftNode->left, rightNode->right, level + 1);
        dfs(leftNode->right, rightNode->left, level + 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

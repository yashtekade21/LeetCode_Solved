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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        return solve(root) != -1;
    }

private:
    int solve(TreeNode* node) {
        if (!node)
            return 0;

        int left = solve(node->left);
        if (left == -1)
            return -1;

        int right = solve(node->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    int sumRootToLeaf(TreeNode* root) { return solve(root, 0); }

private:
    int solve(TreeNode* root, int sum) {
        if (!root)
            return 0;

        sum = 2 * sum + 1 * root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum;

        return solve(root->left, sum) + solve(root->right, sum);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

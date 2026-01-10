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
    unordered_map<int, int> mp;
    int maxDepth = 0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        depth(root, 0);

        return LCA(root);
    }

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || mp[root->val] == maxDepth)
            return root;

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if (left && right)
            return root;

        return left != NULL ? left : right;
    }

    void depth(TreeNode* root, int d) {
        if (!root)
            return;

        maxDepth = max(maxDepth, d);
        mp[root->val] = d;
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

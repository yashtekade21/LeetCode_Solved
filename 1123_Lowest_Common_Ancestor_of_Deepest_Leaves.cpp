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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int, int> mp;
        int maxDepth = 0;
        dfs(root, 0, mp, maxDepth);
        // cout<<maxDepth;

        return lowestCommonAncestor(root, mp, maxDepth);
    }

private:
    void dfs(TreeNode* node, int depth, unordered_map<int, int>& mp,
             int& maxDepth) {
        if (!node)
            return;

        mp[node->val] = depth;

        maxDepth = max(maxDepth, depth);
        dfs(node->left, depth + 1, mp, maxDepth);
        dfs(node->right, depth + 1, mp, maxDepth);
    }

    TreeNode* lowestCommonAncestor(TreeNode* node, unordered_map<int, int>& mp,
                                   int& maxDepth) {
        if (!node || mp[node->val] == maxDepth)
            return node;

        TreeNode *left = lowestCommonAncestor(node->left, mp, maxDepth),
                 *right = lowestCommonAncestor(node->right, mp, maxDepth);

        if (!left)
            return right;
        else if (!right)
            return left;
        else
            return node;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

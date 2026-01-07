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
    const int MOD = 1e9 + 7;
    long long totalSum, ans;
    int maxProduct(TreeNode* root) {
        if (!root)
            return 0;
        totalSum = dfs(root);

        ans = 0;
        dfs(root);

        return ans%MOD;
    }

private:
    long long dfs(TreeNode* root) {
        if (!root)
            return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long sum = root->val + left + right;

        ans = max(ans, (totalSum - sum) * sum);

        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

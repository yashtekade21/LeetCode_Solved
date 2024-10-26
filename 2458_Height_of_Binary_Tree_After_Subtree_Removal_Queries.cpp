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
private:
    int max_height;

    void left_dfs(TreeNode* root, vector<int>& left, int d) {
        if (root == nullptr)
            return;
        left[root->val] = max_height;
        max_height = max(max_height, d);

        left_dfs(root->left, left, d + 1);
        left_dfs(root->right, left, d + 1);
    }

    void right_dfs(TreeNode* root, vector<int>& right, int d) {
        if (root == nullptr)
            return;
        right[root->val] = max_height;
        max_height = max(max_height, d);

        right_dfs(root->right, right, d + 1);
        right_dfs(root->left, right, d + 1);
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> left_depth(100001), right_depth(100001);

        max_height = 0;
        left_dfs(root, left_depth, 0);
        max_height = 0;
        right_dfs(root, right_depth, 0);

        for (int i = 0; i < queries.size(); i++)
            queries[i] = max(left_depth[queries[i]], right_depth[queries[i]]);

        return queries;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

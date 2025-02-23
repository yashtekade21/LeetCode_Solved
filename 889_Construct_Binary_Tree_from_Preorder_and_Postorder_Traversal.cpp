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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();
        int idx = 0;

        return solve(preorder, postorder, 0, n - 1, idx, n);
    }

private:
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int start,
                    int end, int& idx, int& n) {
        if (start > end || idx >= n)
            return nullptr;

        int root_val = preorder[idx];
        TreeNode* node = new TreeNode(root_val);

        if (start == end || idx + 1 >= n) {
            idx++;
            return node;
        }

        int find_val = preorder[idx + 1];
        int i = start;
        for (; i <= end; i++) {
            if (postorder[i] == find_val)
                break;
        }

        idx++;

        node->left = solve(preorder, postorder, start, i, idx, n);
        node->right = solve(preorder, postorder, i + 1, end - 1, idx, n);

        return node;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

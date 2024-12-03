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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = build_tree(postorder, 0, postorder.size() - 1, inorder,
                                    0, inorder.size() - 1, mp);
        return root;
    }

private:
    TreeNode* build_tree(vector<int>& postorder, int pos_start, int pos_end,
                         vector<int>& inorder, int in_start, int in_end,
                         unordered_map<int, int>& mp) {
        if (pos_start > pos_end || in_start > in_end)
            return nullptr;

        TreeNode* node = new TreeNode(postorder[pos_end]);

        int root_idx = mp[node->val];
        int left_nums = root_idx - in_start;

        node->left = build_tree(postorder, pos_start, pos_start + left_nums - 1,
                                inorder, in_start, root_idx - 1, mp);
        node->right =
            build_tree(postorder, pos_start + left_nums, pos_end - 1,
                       inorder, root_idx + 1, in_end, mp);

        return node;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

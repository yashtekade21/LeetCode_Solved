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
    bool isSymmetric(TreeNode* root) { 
        return root == nullptr || check_sym(root->left,root->right);
    }

private:
    bool check_sym(TreeNode*& left, TreeNode*& right) {
        if (left == nullptr || right == nullptr)
            return left == right;

        if (left->val != right->val)
            return false;

        return check_sym(left->left, right->right) &&
               check_sym(left->right, right->left);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

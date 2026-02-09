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
    vector<int> BST;
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);

        return solve(0, (int)BST.size() - 1, root);
    }

private:
    void inOrder(TreeNode* node) {
        if (!node)
            return;

        inOrder(node->left);
        BST.push_back(node->val);
        inOrder(node->right);
    }

    TreeNode* solve(int i, int j, TreeNode* node) {
        if (i > j)
            return nullptr;

        int mid = (i + j) / 2;
        TreeNode* newNode = new TreeNode(BST[mid]);
        newNode->left = solve(i, mid - 1, newNode);
        newNode->right = solve(mid + 1, j, newNode);

        return newNode;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

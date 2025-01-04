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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorder_trav(root, inorder);

        int i = 0, j = inorder.size() - 1;
        while (i < j) {
            int sum = inorder[i] + inorder[j];
            if (sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }
        return false;
    }

private:
    void inorder_trav(TreeNode* node, vector<int>& inorder) {
        if (!node)
            return;
        inorder_trav(node->left,inorder);
        inorder.emplace_back(node->val);
        inorder_trav(node->right,inorder);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

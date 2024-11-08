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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool ltor = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index;
                if (ltor)
                    index = i;
                else
                    index = size - i - 1;

                row[index] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (ltor)
                ltor = false;
            else
                ltor = true;

            result.push_back(row);
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

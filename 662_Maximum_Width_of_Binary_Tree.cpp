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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)
            return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            int mini = q.front().second;
            int first, last;
            for (int i = 0; i < n; i++) {
                long long  idx = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if (i == 0)
                    first = idx;
                if (i == n - 1)
                    last = idx;

                if (temp->left != nullptr)
                    q.push({temp->left, 2 * idx + 1});
                if (temp->right != nullptr)
                    q.push({temp->right, 2 * idx + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

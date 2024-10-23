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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum = levelSum(root);
        updateVal(root, 0, sum);
        root->val = 0;
        return root;
    }

private:
    vector<int> levelSum(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int sum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;

                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            ans.emplace_back(sum);
        }
        return ans;
    }

    void updateVal(TreeNode* root, int level, vector<int> &levelSum) {
        if (root == nullptr || level + 1 >= levelSum.size())
            return;

        int nextLevelSum = levelSum[level + 1];

        if (root->left != nullptr)
            nextLevelSum -= root->left->val;
        if (root->right != nullptr)
            nextLevelSum -= root->right->val;

        if (root->left != nullptr)
            root->left->val = nextLevelSum;
        if (root->right != nullptr)
            root->right->val = nextLevelSum;

        updateVal(root->left, level + 1, levelSum);
        updateVal(root->right, level + 1, levelSum);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        bfs(root, ans);
        return ans;
    }

private:
    void bfs(TreeNode* root, int& level) {
        queue<TreeNode*> q;
        int maxSum = INT_MIN, curLevel = 0;

        q.push(root);
        while (!q.empty()) {
            curLevel++;
            int n = q.size();
            int curSum = 0;

            while (n--) {
                TreeNode* top = q.front();
                curSum += top->val;

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);

                q.pop();
            }
            if (curSum > maxSum) {
                maxSum = curSum;
                level = curLevel;
            }
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

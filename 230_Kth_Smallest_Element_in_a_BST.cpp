/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node= root;
        if(!root)
            return 0;

        queue<TreeNode*> q;
        vector<int> v;
        q.push(node);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            v.emplace_back(top->val);
            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
        }
        sort(begin(v),end(v));
        return v[k-1];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

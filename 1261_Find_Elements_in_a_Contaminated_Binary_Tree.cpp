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
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        root->val = 0;        
        st.insert(root->val);
        dfs(root, root->val,st);
    }

    bool find(int target) {
        return st.find(target) != st.end();
    }

private:
    void dfs(TreeNode* root, int& val,unordered_set<int>& st) {
        if (!root)
            return;

        if (root->left) {
            root->left->val = 2 * val + 1;
            st.insert(root->left->val);
            dfs(root->left, root->left->val,st);
        }
        if (root->right) {
            root->right->val = 2 * val + 2;
            st.insert(root->right->val);
            dfs(root->right, root->right->val,st);
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

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

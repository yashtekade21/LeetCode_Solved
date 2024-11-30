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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;

        reverse_preorder(root,0,ans);
        return ans;
    }
private:
    void reverse_preorder(TreeNode*& root,int level,vector<int>& arr){
        if(root == nullptr)
            return ;
        if(arr.size() == level)
            arr.emplace_back(root->val);
        reverse_preorder(root->right,level+1,arr);
        reverse_preorder(root->left,level+1,arr);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

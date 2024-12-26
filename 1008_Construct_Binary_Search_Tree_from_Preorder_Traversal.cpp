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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder,i,INT_MAX);
    }
private:
    TreeNode* bst(vector<int>& preorder,int& i,int upper_bound){
        if(i==preorder.size() || preorder[i] > upper_bound)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = bst(preorder,i,node->val);
        node->right = bst(preorder,i,upper_bound);
        return node;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

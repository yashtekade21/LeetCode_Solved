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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        
        TreeNode* root =  build_tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
private:
    TreeNode* build_tree(vector<int>& preorder,int pre_start,int pre_end, vector<int>& inorder,int in_start,int in_end,unordered_map<int,int> &mp){
        if(pre_start > pre_end || in_start > in_end)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[pre_start]);

        int root_idx = mp[node->val];
        int left_nums = root_idx - in_start;

        node->left = build_tree(preorder,pre_start+1,pre_start+left_nums,inorder, in_start,root_idx-1,mp);
        node->right = build_tree(preorder,pre_start + left_nums + 1,pre_end,inorder,root_idx+1,in_end,mp);

        return node;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

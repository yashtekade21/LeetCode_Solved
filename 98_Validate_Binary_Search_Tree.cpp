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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        for(int i=0;i<v.size()-1;i++){
            if(v[i] >= v[i+1])
                return false;
        }
        return true;
    }
private:
    void inorder(TreeNode* node,vector<int>& v){
        if(!node)
            return;
        
        inorder(node->left,v);
        v.emplace_back(node->val);
        inorder(node->right,v);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

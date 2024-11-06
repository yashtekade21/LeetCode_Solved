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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        findmax(root,maxi);
        return maxi;
    }
private:
    int findmax(TreeNode* node,int& maxi){
        if(node == nullptr)
            return 0;

        int left = findmax(node->left,maxi);
        int right = findmax(node->right,maxi);
        maxi = max(maxi,left+right);

        return 1+max(left,right);

    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

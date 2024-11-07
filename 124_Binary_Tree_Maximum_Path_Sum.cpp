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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findmax(root,maxi);
        return maxi;
    }
private:
    int findmax(TreeNode* node,int& maxi){
        if(node == nullptr)
            return 0;

        int left = max(0,findmax(node->left,maxi));
        int right = max(0,findmax(node->right,maxi));

        maxi = max(maxi,left+right+node->val);

        return max(left,right)+node->val;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

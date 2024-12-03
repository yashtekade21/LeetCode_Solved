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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;

        int lh = left_height(root);
        int rh = right_height(root);

        if(lh == rh)
            return (int)pow(2,lh)-1;        
        
        return 1 + countNodes(root->left) + countNodes(root->right);

    }
private:
    int left_height(TreeNode* node){
        int h=0;
        while(node != nullptr){
            h++;
            node= node->left;
        }
        return h;
    }
    int right_height(TreeNode* node){
        int h=0;
        while(node != nullptr){
            h++;
            node= node->right;
        }
        return h;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

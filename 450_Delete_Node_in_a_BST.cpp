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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val == key)
            return changelink(root);

        TreeNode* node = root;

        while(node){
            if(node->val > key){
                if(node->left && node->left->val == key){
                    node->left = changelink(node->left);
                    break;
                }
                else
                    node = node->left;
            }
            else{
                if(node->right && node->right->val == key){
                    node->right = changelink(node->right);
                    break;
                }
                else   
                    node = node->right;
            }
        }
        return root;
    }
private:
    TreeNode* changelink(TreeNode* node){
        if(!node->left)
            return node->right;
        else if(!node->right)
            return node->left;
        
        TreeNode* rightChild = node->right;
        TreeNode* lastRightChild = findLastRight(node->left);
        lastRightChild->right = rightChild;
        return node->left;
    }
    TreeNode* findLastRight(TreeNode* node){
        if(!node->right)
            return node;

        return findLastRight(node->right);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0, level = 0, n = traversal.length();

        return solve(traversal,i,level,n);
    }
private:
    TreeNode* solve(string &traversal,int &i,int level,int &n){
        if(i >= n)
            return nullptr;

        int j = i;
        while(j<n && traversal[j] == '-'){
            j++;
        }

        int dash_cnt = j-i;

        if(dash_cnt != level)
            return nullptr;

        i += dash_cnt;
        int num = 0;
        while(i < n && isdigit(traversal[i])){
            num = (num*10) + (traversal[i]-'0');
            i++;
        }

        TreeNode* newnode = new TreeNode(num);

        newnode->left = solve(traversal,i,level+1,n);
        newnode->right = solve(traversal,i,level+1,n);

        return newnode;

    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

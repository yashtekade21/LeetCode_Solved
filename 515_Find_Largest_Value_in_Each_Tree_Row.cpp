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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        return BFS(root);
    }
private:
    vector<int> BFS(TreeNode* node){
        vector<int> max_nodes;
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            int n = q.size();
            int level_max = INT_MIN;
            while(n--){
                TreeNode* top = q.front();
                q.pop();
                if(level_max < top->val)
                    level_max = top->val;

                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            max_nodes.push_back(level_max);
        }
        return max_nodes;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

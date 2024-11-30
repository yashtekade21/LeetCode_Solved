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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int x=it.second.first,depth = it.second.second;
            nodes[x][depth].insert(temp->val);

            if(temp->left != nullptr)
                q.push({temp->left,{x-1,depth+1}});
            if(temp->right != nullptr)
                q.push({temp->right,{x+1,depth+1}});
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> vertical;
            for(auto q : p.second)
                vertical.insert(vertical.end(),q.second.begin(),q.second.end());
            ans.emplace_back(vertical);
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

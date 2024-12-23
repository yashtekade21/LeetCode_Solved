/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int min_swap = 0;

        q.push(root);
        

        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                vec.emplace_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            min_op(vec,min_swap);
        }
        return min_swap;
    }
private:
    void min_op(vector<int>& vec,int& min_swap){
        vector<int> sorted = vec;
        sort(sorted.begin(),sorted.end());
        int size = sorted.size();
        unordered_map<int,int> mp;

        for(int i=0;i<size;i++)
            mp[vec[i]] = i;

        for(int i=0;i<size;i++){
            if(sorted[i] != vec[i]){
                int idx = mp[sorted[i]];
                mp[vec[i]] = idx;
                mp[vec[idx]] = i;
                swap(vec[idx],vec[i]);
                min_swap++;
            }
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
